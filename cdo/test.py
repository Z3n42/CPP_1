# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 17:18:56 by ingonzal          #+#    #+#              #
#    Updated: 2022/08/11 17:26:01 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/local/bin/python3
import requests
import sys
import argparse
import pprint

def simple_get(url, args, flag, argflag):
    for value in url.values():
        if value[flag] in argflag:
            print("******* " + value[flag] + " *******")
            pprint.pprint(value)
            print('\n')

def list_get(url, args, flag, argflag):
    for value in url.values():
        lang = value[flag]
        for i in lang: 
            if i in argflag:
                print("******* " + i + " *******")
                pprint.pprint(value)
                print('\n')

def select_flag(url, args):
    if args.name:
        argflag = args.name
        flag = "Name"
        simple_get(url, args, flag, argflag)
    if args.type:
        argflag = args.type
        flag = "Type"
        simple_get(url, args, flag, argflag)
    if args.language:
        argflag = args.language
        flag = "Language"
        list_get(url, args, flag, argflag)
    if args.owner:
        argflag = args.owner
        flag = "Owner"
        simple_get(url, args, flag, argflag)
    if args.website:
        argflag = args.website
        flag = "Website"
        simple_get(url, args, flag, argflag)
    if args.country:
        argflag = args.country
        flag = "Country"
        simple_get(url, args, flag, argflag)

def connect():
    url = 'https://z3n42.github.io'
    try: 
        json = requests.get(url).json()
        return (json)
    except:
        print(url + " has a connection problem")

def parser():
    parser = argparse.ArgumentParser(description='Filter Newsletter')
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument('-n', '--name', nargs='+', help='Insert a "name" of a Newsletter')
    group.add_argument('-t', '--type', nargs='+', help='Insert "type" of a Newsletter')
    group.add_argument('-l', '--language', nargs='+', help='Insert "lenguage" of a Newsletter')
    group.add_argument('-o', '--owner', nargs='+', help='Insert the name of the "owner" of a Newsletter')
    group.add_argument('-w', '--website', nargs='+', help='Insert the url of the "website" of a Newsletter')
    group.add_argument('-c', '--country', nargs='+', help='Insert the name of the "country" of a Newsletter')
    args=parser.parse_args()
    return (args)

if __name__ == "__main__":
    url = connect()
    args = parser()
    select_flag(url, args)
