#!/usr/local/bin/python3
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ex05.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 13:05:22 by ingonzal          #+#    #+#              #
#    Updated: 2022/09/28 13:05:22 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from ex04 import *
import pprint
import json

def fase04():
    data = token()
    availables = data["availables"]
    
    for each in availables:
        if availables[each]["type"] == "search" and availables[each]["description"].isupper():
            return availables[each]["url"]

# if __name__ == "__main__":
#     ret = fase04()
#     print(ret)
