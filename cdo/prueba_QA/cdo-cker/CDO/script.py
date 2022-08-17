#!/usr/local/bin/python3
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

import requests
import sys
import argparse
import pprint
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from pyvirtualdisplay import Display

# This Script only runs inside the attached Docker enviroment

def selena(url):
    # set xvfb display since there is no GUI in docker container.
    display = Display(visible=0, size=(800, 600))
    display.start()
    
    chrome_options = Options()
    chrome_options.add_argument('--no-sandbox')
    chrome_options.add_argument('--disable-dev-shm-usage')

    driver = webdriver.Chrome(options=chrome_options)
    driver.get(url)

    title = driver.title

    driver.quit()
    display.stop()
    return(title)

def pretty_print(param_funct):
    def mod(url, args, flag, argflag):
        print("\n******* " + flag + " flag *******\n")
        param_funct(url, args, flag, argflag)
        print("\n _______END_______ \n")
    return (mod)

@pretty_print
def web_test(url, args, flag, argflag):
    ret = []
    for value in url.values():
        if value[flag] in argflag:
            title = selena(value["Website"])   
            ret.append(value["Name"] + " : " + title)
    if ret != []:
        pprint.pprint(ret)
    else:
        print("    Don´t exist")
    return (ret)

@pretty_print
def simple_get(url, args, flag, argflag):
    ret = []
    for value in url.values():
        if value[flag] in argflag:
            if flag == "Name":
                ret = value
            else:
                ret.append(value["Name"])
    if ret != []:
        pprint.pprint(ret)
    else:
        print("    Don´t exist")
    return (ret)

@pretty_print
def list_get(url, args, flag, argflag):
    ret = []
    for value in url.values():
        lang = value[flag]
        for i in lang: 
            if i in argflag:
                if value["Name"] not in ret:
                    ret.append(value["Name"])
    if ret != []:
        pprint.pprint(ret)
    else:
        print("    Don´t exist")
    return (ret)

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
        web_test(url, args, flag, argflag)
    if args.country:
        argflag = args.country
        flag = "Country"
        simple_get(url, args, flag, argflag)

def connect():
    url = 'https://z3n42.github.io'
    try: 
        ret = requests.get(url)
        json = requests.get(url).json()
        return (json)
    except:
        print(url + " has a connection problem" + ret)
        return (ret)

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
