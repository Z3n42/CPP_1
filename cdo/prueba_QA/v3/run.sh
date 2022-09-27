#!/bin/bash

function init
{
	# if chrome version changes and chromedriver manual handler and build fails, 
	#jumps to automatic handler build 
	if ! docker build --platform=linux/amd64 -t prueba_qa . ;
		then printf "\ec" &&
			echo "Manual chromedriver build failed, Jump to Automatic chromedriver build" && 
			docker build -f ./automatic/Dockerfile --platform=linux/amd64 -t prueba_qa . 
	fi &&
	printf "\ec" &&
	printf "\n" &&
	echo "Run \"./script.py -[flag] [Argument]\" or Run \"behave\"" &&
	printf "\n" &&
	docker run --name ingonzal_qa --rm -it prueba_qa /bin/bash
}

function clean
{
	docker rmi prueba_qa
	docker rmi python:3.7-slim-buster
	printf "\ec" &&
	printf "\n" &&
	echo "ingonzal_qa Docker container and prueba_qa Docker image cleaned" &&
	printf "\n"
}

if [ "$1" = "start" ]; then
	init
elif [ "$1" = "clean" ]; then
	clean
else
	echo "Error: Wrong argument :"
	echo "	Try => ./run.sh start"
	printf "\n" &&
	echo "	Or When finished :"
	echo "	Try => ./run.sh clean"
fi
