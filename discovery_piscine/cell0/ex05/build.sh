#!/bin/bash

i=$#

if [ $# = 0 ];
	then
		echo "No arguments supplied";
else
	for num in "$@"
	do
		mkdir ex$num
		((i++))	
	done
fi

#end script
