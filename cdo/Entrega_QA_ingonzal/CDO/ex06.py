#!/usr/local/bin/python3
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ex06.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 13:18:50 by ingonzal          #+#    #+#              #
#    Updated: 2022/09/28 13:18:50 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from ex04 import *
from ex05 import *
import pprint
import json
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from pyvirtualdisplay import Display


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

def fase05():
    url = fase04()
    return selena(url)

if __name__ == "__main__":
    ret = fase05()
    print(ret)
