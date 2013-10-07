# weight.py
# Author: Roberto D'Auria

# Self-explaining.

def sono_grasso():
	height = input("Quanto sei alto? ")
	weight = input("Quanto pesi? ")
	if weight > height:
		return "Si"
	else:
		return "No"

name = input("Inserisci il nome: ")
surname = input("Inserisci il cognome: ")
result = sono_grasso()
if result is "Si":
	print("Sei grasso")
