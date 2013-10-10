# compito1.py
# Author: Roberto D'Auria

n = 0
secret = 5
while n != secret:
    n = int(input("Inserisci un numero da 1 a 10: "))
    if n == 1:
        print("Bravo, hai inserito un numero piccolo")
    elif n == 10:
        print("Bravo, hai inserito un numero grande")

print("Fine!")