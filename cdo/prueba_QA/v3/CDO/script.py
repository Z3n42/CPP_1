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
import re
import argparse
import pprint
import logging
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from pyvirtualdisplay import Display

logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s') 
handler = logging.FileHandler('prueba_qa.log')
handler.setFormatter(formatter)
logger.addHandler(handler)


# !!! selenium part is made to works inside the attached Docker enviroment because xvfb dependence !!!

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

# Decoration function 
def pretty_print(param_funct):
    def mod(data, args, flag, argflag):
        ret = param_funct(data, args, flag, argflag)
        print("\n****** " + flag + " flag ******\n")
        pprint.pprint(ret)
        print("\n _______END_______ \n")
        return (ret)
    return (mod)

# This function uses Selenium to get website title
@pretty_print
def web_test(data, args, flag, argflag):
    print("Making conection, be patient please...\n")
    ret = []
    for value in data.values():
        if value[flag] in argflag:
            try :
                title = selena(value["Website"])   
                ret.append(value["Name"] + " : " + title)
            except FileNotFoundError:
                ret.append("Selenium part is made to works inside the attached Docker enviroment because the xvfb dependence")
    if ret == []:
        ret = "Don´t exist!!!"
    return (ret)

# This function gets almost all cases
@pretty_print
def simple_get(data, args, flag, argflag):
    ret = []
    for value in data.values():
        if value[flag] in argflag:
            if flag == "Name":
                ret = value
            else:
                ret.append(value["Name"])
    if ret == []:
        ret.append("Don´t exist!!!")
    return (ret)

# This function get list values
@pretty_print
def list_get(data, args, flag, argflag):
    ret = []
    for value in data.values():
        lang = value[flag]
        for i in lang: 
            if i in argflag:
                if value["Name"] not in ret:
                    ret.append(value["Name"])
    if ret == []:
        ret.append("Don´t exist!!!")
    return (ret)

# Main object where recieve the parsed arguments and call to the proper function
class Qa(object):
    def __init__(self, data, args, ret):
        self.data = data
        self.args = args
        self.ret = ret

    def select_flag(self):
        if self.args.name:
            argflag = self.args.name
            flag = "Name"
            self.ret = simple_get(self.data, self.args, flag, argflag)
        if self.args.type:
            argflag = self.args.type
            flag = "Type"
            self.ret = simple_get(self.data, self.args, flag, argflag)
        if self.args.language:
            argflag = self.args.language
            flag = "Language"
            self.ret = list_get(self.data, self.args, flag, argflag)
        if self.args.owner:
            argflag = self.args.owner
            flag = "Owner"
            self.ret = simple_get(self.data, self.args, flag, argflag)
        if self.args.website:
            argflag = self.args.website
            flag = "Website"
            self.ret = web_test(self.data, self.args, flag, argflag)
        if self.args.country:
            argflag = self.args.country
            flag = "Country"
            self.ret = simple_get(self.data, self.args, flag, argflag)
        try:
            logger.info("Flag : " + flag + " => " + argflag)
            logger.info(self.ret)
        except:
            exit()
        return (self.ret)

# Connnect with the api
def connect():
    url = 'https://z3n42.github.io'
    try: 
       ret = requests.get(url)
    except:
        print("\n" + url + " has a connection problem\n")
        exit()
    else:
        logger.info(ret)
        return (ret)

# Argument parsing
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

# Main
if __name__ == "__main__":
    data = connect().json()
    args = parser()
    init = Qa(data, args, None)
    ret = init.select_flag()
