# urllib-ilmeteo.py

import urllib.request

page = urllib.request.urlopen("http://www.ilmeteo.it/portale/meteo/previsioni.php?citta=Perugia&c=5096&gm=7")
find_start = "class=\"situa2"
find_end = "<tr class=\"situa2 rep-new\""

text = page.read().decode("utf8")

start_pos = text.find(find_start)
end_pos = text.find(find_end)

text = text[start_pos:end_pos]

find_start = "&deg;&nbsp;&nbsp;<"

start_pos = text.find(find_start)

temp = text[start_pos-2:start_pos]

if temp:
	print("Ultima temperatura rilevata a Perugia: " + temp + "°C")
else:
	print("Nessuna rilevazione della temperatura disponibile")
