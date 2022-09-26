#!/bin/bash

function build
{
    docker build ~/42/Docker_Valgrind -t dvalg:latest
}

function BuildDisp
{
    docker build ~/42/Docker_Valgrind/Display -t dvalg:latest
}

function clean
{
	rm -rf ~/42/Docker_Valgrind/config
	docker system prune
}

function DeepClean
{
	rm -rf ~/42/Docker_Valgrind/config
	docker system prune -a
}


function RunDisp
{
	rm -rf ~/42/Docker_Valgrind/config
	mkdir ~/42/Docker_Valgrind/config
	cp  ~/42/Docker_Valgrind/symlinks/.* ~/42/Docker_Valgrind/config 2>/dev/null
	cp -rf ~/.cache ~/42/Docker_Valgrind/config 
	cp -rf ~/.oh-my-zsh ~/42/Docker_Valgrind/config 
	cp -rf ~/.vim ~/42/Docker_Valgrind/config 
	cp  ~/.bash_history ~/42/Docker_Valgrind/config 2>/dev/null
	cp  ~/.viminfo ~/42/Docker_Valgrind/config 
	cp  ~/.vimrc ~/42/Docker_Valgrind/config 
	cp  ~/.zsh_history ~/42/Docker_Valgrind/config 
	xhost + 127.0.0.1
    docker run -it --rm --name valgrind -e DISPLAY=host.docker.internal:0 -p 2022:22 -v ${PWD}:/valgrind -v ~/42/Docker_Valgrind/config:/root dvalg
}

function run
{
	rm -rf ~/42/Docker_Valgrind/config
	mkdir ~/42/Docker_Valgrind/config
	cp  ~/42/Docker_Valgrind/symlinks/.* ~/42/Docker_Valgrind/config 2>/dev/null
	cp -rf ~/.cache ~/42/Docker_Valgrind/config 
	cp -rf ~/.oh-my-zsh ~/42/Docker_Valgrind/config 
	cp -rf ~/.vim ~/42/Docker_Valgrind/config 
	cp  ~/.bash_history ~/42/Docker_Valgrind/config 2>/dev/null
	cp  ~/.viminfo ~/42/Docker_Valgrind/config 
	cp  ~/.vimrc ~/42/Docker_Valgrind/config 
	cp  ~/.zsh_history ~/42/Docker_Valgrind/config 
    docker run -it --rm --name valgrind -p 2022:22 -v ${PWD}:/valgrind -v ~/42/Docker_Valgrind/config:/root dvalg
}

if [[ "$1" = "run" ]]; then
    run
elif [[ "$1" = "build" ]]; then
    build
elif [[ "$1" = "clean" ]]; then
	clean
elif [[ "$1" = "DeepClean" ]]; then
	DeepClean
elif [[ "$1" = "BuildDisp" ]]; then
	BuildDisp
elif [[ "$1" = "RunDisp" ]]; then
	RunDisp
else
    echo "Error: Wrong parameter"
    echo "  build"
    echo "  run"
    echo "  clean"
    echo "  DeepClean"
    echo "  BuildDisp"
    echo "  RunDisp"
    echo "Your parameter is => "$1
fi
