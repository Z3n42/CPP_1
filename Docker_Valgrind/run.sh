#!/bin/bash

function build
{
    docker build . -t cpp:latest
}

function run
{
    #docker run -it --rm --name cpp_env -v ${PWD}:/tmp/ cpp /bin/bash
    docker run -itd --rm --name cpp_env -p 2022:22 -v ${PWD}:/tmp/ -v ${PWD}/config:/root cpp
}

if [[ "$1" = "run" ]]; then
    run
elif [[ "$1" = "build" ]]; then
    build
elif [[ "$1" = "in" ]]; then
    docker exec -it cpp_env /bin/zsh
elif [[ "$1" = "id" ]]; then
    id -a
else
    echo "Error: Wrong parameter"
    echo "  run"
    echo "  build"
    echo "  id"
    echo "Your parameter is => "$1
fi
