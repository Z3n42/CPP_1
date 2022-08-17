# import external libraries.
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from pyvirtualdisplay import Display

# set xvfb display since there is no GUI in docker container.
display = Display(visible=0, size=(800, 600))
display.start()

chrome_options = Options()
chrome_options.add_argument('--no-sandbox')
chrome_options.add_argument('--disable-dev-shm-usage')

print('building session')
driver = webdriver.Chrome(options=chrome_options)

## DO STUFF
# driver.get("https://google.es")
driver.get("https://www.elpais.es")
title = driver.title
print(title)
# assert title == "Google"



# close chromedriver and display
driver.quit()
display.stop()
