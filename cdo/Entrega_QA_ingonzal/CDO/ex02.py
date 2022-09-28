#!/usr/local/bin/python3
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ex02.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 11:20:51 by ingonzal          #+#    #+#              #
#    Updated: 2022/09/28 11:23:16 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import json

def oauth():
    with open("credentials.json") as archivo:
        data = json.load(archivo)

    ret = []
    for keys in data["OAuth"].values():
        ret.append(keys)
    ret = tuple(ret)
    return ret


# if __name__ == "__main__":

#     data = oauth()
#     print(data)
