#!/bin/bash
if [ $# = 0 ];
	then
		echo "No arguments supplied";
elif [ $# = 1 ];
	then
		echo "$1";
elif [ $# = 2 ];
	then
		echo "$1";
		echo "$2";
elif [ $# -ge 3 ];
	then
		echo "$1";
		echo "$2";
		echo "$3";
fi
#end script
