# starbuzz.py
# Author: Roberto D'Auria

# Read the beans' price from a website and print it only when it's below $4.74
import time 
import urllib.request

price = 99.99

def get_price():
    page = urllib.request.urlopen("http://beans.itcarlow.ie/prices-loyalty.html")
    text = page.read().decode("utf8")

    start_of_price = text.find(">$") + 2
    end_of_price = start_of_price + 4
    return float(text[start_of_price:end_of_price])

while price > 4.74:
    time.sleep(10)
    price = get_price()

print("Buy at: $" + str(price))