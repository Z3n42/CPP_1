#!/usr/local/bin/python3
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ex04.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 12:45:46 by ingonzal          #+#    #+#              #
#    Updated: 2022/09/28 12:45:46 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from ex02 import *
from ex03 import *
import pprint
import json

def token():
    with open("credentials.json") as archivo:
        data = json.load(archivo)

    url = data["Api_url"]
    data = connect()
    token = data["access_token"]
    headers = {"Authorization": "Bearer " + token}
    response = requests.get(url, headers=headers)

    return response.json()

# if __name__ == "__main__":
#     data = token()
#     pprint. pprint(data)
