# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Tarea1.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 17:15:25 by ingonzal          #+#    #+#              #
#    Updated: 2022/10/11 17:15:32 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

Regions=$(aws ec2 describe-regions --all-regions | jq -r '.Regions | .[] | .RegionName + " " + .OptInStatus'  | grep -v not-opted-in | cut -d' ' -f1)

for each in ${Regions[@]}
do
        printf "\n" &&
        echo "Trying to describe availability zones from region => " ${each} &&
        aws ec2 describe-availability-zones --region ${each} --output table
done
