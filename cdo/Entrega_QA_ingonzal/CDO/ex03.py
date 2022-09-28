#!/usr/local/bin/python3
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ex03.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 11:49:00 by ingonzal          #+#    #+#              #
#    Updated: 2022/09/28 11:49:00 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from ex02 import *
import base64, requests, sys
import json

def connect():
    with open("credentials.json") as archivo:
        data = json.load(archivo)

    url = data["Authorization_url"]


    oaut = oauth()
    client_id = oaut[0] 
    client_secret = oaut[1]

    authorization = base64.b64encode(bytes(client_id + ":" + client_secret, "ISO-8859-1")).decode("ascii")


    headers = {
        "Authorization": f"Basic {authorization}",
        "Content-Type": "application/x-www-form-urlencoded"
    }
    body = {
        "grant_type": "client_credentials"
    }

    try:
        response = requests.post(url, data=body, headers=headers)
    except:
        print("\n" + url + " has a connection problem\n")
        exit()
    else:
        return (response.json())


# if __name__ == "__main__":

#     data = connect().json()
#     print(data)
