#!/bin/sh
find . -type f -o -type d | wc -l | awk -F' ' '{ print$1 }'
