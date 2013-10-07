# starbuzz.py
import time 
import urllib.request

price = 99.99

while price > 4.74:
	time.sleep(900)
	page = urllib.request.urlopen("http://beans.itcarlow.ie/prices-loyalty.html")
	text = page.read().decode("utf8")

	start_of_price = text.find(">$") + 2
	end_of_price = start_of_price + 4
	price = float(text[start_of_price:end_of_price])

print("Buy at: " + str(price))