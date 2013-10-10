# compito2-len.py
# Author: Roberto D'Auria

# Works using the len() function, which gives the length of a given object
# i.e. len("foo") is 3

city = input("Inserisci la città di nascita: ") # len(city) <= 20
i = 0
flag = False

while i < len(city) and not flag:
    if city[i] == 'a' or city[i] == "A":
        print("Carattere a in posizione: " + str(i))
        flag = True
    i += 1

if not flag:
    print("20")