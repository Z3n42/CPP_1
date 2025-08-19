#!/bin/sh

# install dependencies
# Define the flag file path
FLAG_FILE="/tmp/ng_build_done"

# Check if the build has already been done
if [ ! -f "$FLAG_FILE" ]; then
    npm install

    # start the Angular production server
    ng build

    touch "$FLAG_FILE"
fi

exec "$@"
