# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Tarea2.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 17:15:00 by ingonzal          #+#    #+#              #
#    Updated: 2022/10/11 17:15:11 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

aws service-quotas list-service-quotas --service-code ec2 --query "Quotas[?contains(QuotaName, ' T')].[QuotaName, Value]" --output table
