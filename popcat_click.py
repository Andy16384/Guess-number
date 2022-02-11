    # Action Chains 自動玩網頁小遊戲
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys
import time, os, wget

PATH = "C:/Users/USER/Desktop/Programing/Python/chromedriver.exe"
driver = webdriver.Chrome(PATH)
driver.get("https://popcat.click/")
do = WebDriverWait(driver, 10).until(
    EC.presence_of_element_located((By.CLASS_NAME, 'title'))
)
while True:
    do.click()
    