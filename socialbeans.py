# socialbeans.py
# Author: Roberto D'Auria

# Read beans price from a webpage and post it on Twitter and Facebook

import fb
import urllib.request
from twitter import Twitter, OAuth

TWITTER_OAUTH_TOKEN = ""
TWITTER_OAUTH_SECRET = ""
TWITTER_CONSUMER_KEY = ""
TWITTER_CONSUMER_SECRET = ""

FB_OAUTH_TOKEN = ""

def get_price():
    page = urllib.request.urlopen("http://beans.itcarlow.ie/prices-loyalty.html")
    text = page.read().decode("utf8")

    start_of_price = text.find(">$") + 2
    end_of_price = start_of_price + 4
    return float(text[start_of_price:end_of_price])

# Get beans price
beans_price = get_price()

# Create a Twitter object passing OAuth data
tw = Twitter(
    auth=OAuth(TWITTER_OAUTH_TOKEN, TWITTER_OAUTH_SECRET, TWITTER_CONSUMER_KEY, TWITTER_CONSUMER_SECRET)
)

# Tweet the price
tw.statuses.update(status="Beans price: " + str(beans_price))

facebook = fb.graph.api(FB_OAUTH_TOKEN)
facebook.publish(cat="feed", id="me", message="Beans price: " + str(beans_price))
