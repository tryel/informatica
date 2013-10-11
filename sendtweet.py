# sendtweet.py
# Author: Roberto D'Auria

# Get a OAuth valid token and send a tweet

from twitter import Twitter, OAuth
OAUTH_TOKEN = ""
OAUTH_SECRET = ""
CONSUMER_KEY = ""
CONSUMER_SECRET = ""

tw = Twitter(
        auth=OAuth(OAUTH_TOKEN, OAUTH_SECRET,
                   CONSUMER_KEY, CONSUMER_SECRET)
        )

tw.statuses.update(
        status="It works!"
        )
