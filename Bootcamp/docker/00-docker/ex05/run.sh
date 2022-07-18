#!/bin/bash

if [ "$1" = "run" ]; then
	docker run -it --rm -v ~/42/cursus/4Ring_Pass/philosophers_pass/philo_correct:/home valgrind /bin/bash
elif [ "$1" = "run-new" ]; then
	docker run -it --rm -v ~/42/cursus/4Ring_Pass/philosophers_pass/philo_correct:/home new_valgrind /bin/bash
else
	echo "Error: Wrong argument"
	echo "	run"
	echo "	run-new"
	echo "Your input was -> "$1
fi
