# compito2.py

city = input("Inserisci la città di nascita: ") # len(city) <= 20
i = 0
flag = False

while i < 20 and not flag:
	city += "0"
	if city[i] == 'a' or city[i] == "A":
		print("Carattere a in posizione: " + str(i))
		flag = True
	i += 1

if not flag:
	print("20")