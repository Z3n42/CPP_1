#!/bin/bash

set -e 

IMAGE_BASE_NAME="wil42/playground"
VERSION_V1="v1"
VERSION_V2="v2"
REPO_DIR="./will_app"
DEPLOYMENT_FILE_BASENAME="manifests/deployment.yaml"
DEPLOYMENT_FILE_FULL_PATH="${REPO_DIR}/${DEPLOYMENT_FILE_BASENAME}"
TIMESTAMP=$(date '+%Y-%m-%d %H:%M:%S')

# Submodule management
echo ""
echo "=== SUBMODULE MANAGEMENT ==="
echo "Checking submodule status..."

# Check if submodule directory exists and is initialized
if [ ! -d "$REPO_DIR" ] || [ ! -f "${REPO_DIR}/.git" ]; then
  echo "Submodule not initialized. Initializing and updating..."
  git submodule update --init --recursive
  echo "Submodule initialized successfully."
else
  echo "Checking and updating submodule to latest version..."
  
  # This command handles everything: fetch, compare, and update if needed
  if git submodule update --remote --recursive | grep -q "Submodule path"; then
    echo "Submodule updated to latest version."
    
    # Update submodule reference in parent repository
    git add "$REPO_DIR"
    if ! git diff --cached --quiet; then
      git commit -m "Update submodule to latest commit on $TIMESTAMP"
      echo "Parent repository updated with new submodule reference."
    fi
  else
    echo "Submodule is already up to date."
  fi
fi

echo ""
echo "=== REPOSITORY VALIDATION ==="

# Check if repository directory exists (after submodule operations)
if [ ! -d "$REPO_DIR" ]; then
  echo "Error: Repository directory '$REPO_DIR' not found."
  exit 1
fi

# Check if .git directory exists within the repo_dir (basic check for a Git repo)
if [ ! -f "${REPO_DIR}/.git" ]; then
  echo "Error: '$REPO_DIR' does not appear to be a Git repository (missing .git directory)."
  exit 1
fi

# Check if deployment.yaml exists
if [ ! -f "$DEPLOYMENT_FILE_FULL_PATH" ]; then
  echo "Error: $DEPLOYMENT_FILE_FULL_PATH not found."
  exit 1
fi

echo "All repository validations passed."

echo ""
echo "=== BRANCH SYNCHRONIZATION ==="

# Ensure submodule is on a branch BEFORE making any changes
echo "Ensuring submodule is on a proper branch for commit operations..."
if ! git -C "$REPO_DIR" symbolic-ref -q HEAD >/dev/null 2>&1; then
  echo "Submodule is in detached HEAD. Switching to main branch..."
  git -C "$REPO_DIR" checkout -B main 2>/dev/null
  echo "Switched to main branch."
  
  # Synchronize local main branch with remote
  echo "Synchronizing local main branch with remote..."
  git -C "$REPO_DIR" pull origin main 2>/dev/null || echo "Sync completed."
else
  echo "Submodule is already on a branch."
  
  # Also synchronize if already on a branch
  echo "Synchronizing current branch with remote..."
  git -C "$REPO_DIR" pull 2>/dev/null || echo "Sync completed."
fi

echo ""
echo "=== VERSION MANAGEMENT ==="

CURRENT_VERSION=""
NEW_VERSION=""
COMMIT_MESSAGE=""

echo "Checking current image version in $DEPLOYMENT_FILE_FULL_PATH..."

if grep -q "${IMAGE_BASE_NAME}:${VERSION_V1}" "$DEPLOYMENT_FILE_FULL_PATH"; then
  CURRENT_VERSION=$VERSION_V1
  NEW_VERSION=$VERSION_V2
  echo "Current version is $CURRENT_VERSION. Changing to $NEW_VERSION."
  sed -i "s|${IMAGE_BASE_NAME}:${VERSION_V1}|${IMAGE_BASE_NAME}:${NEW_VERSION}|g" "$DEPLOYMENT_FILE_FULL_PATH"
  COMMIT_MESSAGE="version update to $NEW_VERSION on $TIMESTAMP"
elif grep -q "${IMAGE_BASE_NAME}:${VERSION_V2}" "$DEPLOYMENT_FILE_FULL_PATH"; then
  CURRENT_VERSION=$VERSION_V2
  NEW_VERSION=$VERSION_V1
  echo "Current version is $CURRENT_VERSION. Changing to $NEW_VERSION."
  sed -i "s|${IMAGE_BASE_NAME}:${VERSION_V2}|${IMAGE_BASE_NAME}:${NEW_VERSION}|g" "$DEPLOYMENT_FILE_FULL_PATH"
  COMMIT_MESSAGE="version update to $NEW_VERSION on $TIMESTAMP"
else
  echo "Error: Neither ${IMAGE_BASE_NAME}:${VERSION_V1} nor ${IMAGE_BASE_NAME}:${VERSION_V2} found in $DEPLOYMENT_FILE_FULL_PATH."
  exit 1
fi

echo "$DEPLOYMENT_FILE_FULL_PATH updated successfully."

echo "Verifying change in $DEPLOYMENT_FILE_FULL_PATH:"
grep "${IMAGE_BASE_NAME}:${NEW_VERSION}" "$DEPLOYMENT_FILE_FULL_PATH"

echo ""
echo "=== GIT OPERATIONS ==="

# Git operations  
echo "Staging $DEPLOYMENT_FILE_BASENAME in repository $REPO_DIR..."
git -C "$REPO_DIR" add "$DEPLOYMENT_FILE_BASENAME"

echo "Committing in repository $REPO_DIR with message: '$COMMIT_MESSAGE'..."
git -C "$REPO_DIR" commit -m "$COMMIT_MESSAGE"

echo "Pushing repository $REPO_DIR to remote..."
git -C "$REPO_DIR" push

echo ""
echo "=== COMPLETION ==="
echo "Version in $REPO_DIR toggled to $NEW_VERSION, committed, and pushed successfully on $TIMESTAMP."
