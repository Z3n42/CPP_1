# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    req.py                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 17:46:47 by ingonzal          #+#    #+#              #
#    Updated: 2022/08/16 15:24:01 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import selenium
import requests
import os
# import pathlib

# r = requests.get('https://api.github.com/events')
# print (r.text)
# payload = {'key1': 'value1', 'key2': ['value2', 'value3']}

# r = requests.get('https://httpbin.org/get', params=payload)
# print(r.text)

from selenium import webdriver
# from selenium.webdriver.common.by import By
# from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.common.desired_capabilities import DesiredCapabilities


def test_eight_components():
    # path = "./chromedriver"
    # driver = webdriver.Chrome(path)
    # Service(ChromeDriverManager().install())
    # s = Service('./chromedriver')
    # os.chmod('/home/seluser/.wdm/drivers/chromedriver/linux64/104.0.5112.79', 777)
    # driver = webdriver.Chrome('/root/.wdm/drivers/chromedriver/linux64/104.0.5112.79')
    options = webdriver.ChromeOptions()
    # options.add_experimental_option("prefs", {"profile.managed_default_content_settings.images": 2}) 
    options.add_argument("--no-sandbox")
    # options.setBinary("/opt/google/chrome")
    options.add_argument("--disable-setuid-sandbox") 
    options.add_argument("--remote-debugging-port=9222")
    options.add_argument("--disable-dev-shm-using")
    options.add_argument('--disable-dev-shm-usage')
    options.add_argument("--disable-extensions") 
    options.add_argument("--disable-gpu") 
    options.add_argument("start-maximized") 
    options.add_argument("disable-infobars")
    options.add_argument(r"user-data-dir=.\cookies\\test") 
    options.add_argument('--ignore-ssl-errors=yes')
    options.add_argument('--ignore-certificate-errors')
    # driver = webdriver.Chrome(chrome_options=options)
    driver = webdriver.Chrome('./chromedriver', options=options)
    # driver = webdriver.Chrome('/home/seluser/.wdm/drivers/chromedriver/linux64/104.0.5112.79', options=options)
    # driver = webdriver.Remote(Service(ChromeDriverManager().install()), options=options)
    # driver.get("https://www.google.com")

    driver.get("https://google.es")

    title = driver.title
    assert title == "Google"

    driver.implicitly_wait()

    search_box = driver.find_element(by=By.NAME, value="q")
    search_button = driver.find_element(by=By.NAME, value="btnK")

    search_box.send_keys("Selenium")
    search_button.click()

    search_box = driver.find_element(by=By.NAME, value="q")
    value = search_box.get_attribute("value")
    assert value == "Selenium"

    # driver.quit()


test_eight_components()
