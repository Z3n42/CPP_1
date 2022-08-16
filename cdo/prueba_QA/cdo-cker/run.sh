#!/bin/bash

if [ "$1" = "start" ]; then
	docker build -t qa . &&
	printf "\ec" &&
	printf "\n" &&
	echo "Run \"./script.py -[flag] [Argument]\" or Run \"behave\"" &&
	printf "\n" &&
	docker run --rm -it -p 4444:4444 qa /bin/bash
else
	echo "Error: Wrong argument"
	 echo "	Try ./run.sh start"
fi
