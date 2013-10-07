# urllib-magic.py
# Author: Roberto D'Auria

# Read a random magic card from magiccards.info and print its name

import urllib.request

page = urllib.request.urlopen("http://magiccards.info/random.html")
to_find = "<span style=\"font-size: 1.5em;\">"

text = page.read().decode("utf8")
start_pos = text.find(to_find)

text = text[start_pos:start_pos+200]
start_find = ".html\">"
end_find = "</a>"

start_pos = text.find(start_find) + 7
end_pos = text.find(end_find)

print("Card name: " + text[start_pos:end_pos])