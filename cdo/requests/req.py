# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    req.py                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 17:46:47 by ingonzal          #+#    #+#              #
#    Updated: 2022/07/01 18:47:19 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import requests

# r = requests.get('https://api.github.com/events')
# print (r.text)
# payload = {'key1': 'value1', 'key2': ['value2', 'value3']}

# r = requests.get('https://httpbin.org/get', params=payload)
# print(r.text)

from selenium import webdriver
from selenium.webdriver.common.by import By


def test_eight_components():
    driver = webdriver.Safari()

    driver.get("https://google.es")

    title = driver.title
    assert title == "Google"

    driver.implicitly_wait(20)

    search_box = driver.find_element(by=By.NAME, value="q")
    search_button = driver.find_element(by=By.NAME, value="btnK")

    search_box.send_keys("Selenium")
    search_button.click()

    search_box = driver.find_element(by=By.NAME, value="q")
    value = search_box.get_attribute("value")
    assert value == "Selenium"

    # driver.quit()


test_eight_components()
