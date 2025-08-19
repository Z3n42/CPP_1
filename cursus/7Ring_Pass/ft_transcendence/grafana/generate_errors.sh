#!/bin/bash

# URL of your Django application where HTTP 500 error will be generated
URL="https://localhost:8443/user/test-error/"

# Number of errors to generate (modify this number as necessary)
NUM_ERRORS=10

echo "Starting the generation of $NUM_ERRORS HTTP 500 errors at $URL"

# Loop to perform the requests
for i in $(seq 1 $NUM_ERRORS); do
  curl -k $URL
  echo "Error $i generated"
done

echo "Process completed. $NUM_ERRORS errors have been generated."