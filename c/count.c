/* Authors: Martina Fortunelli & Roberto D'Auria
 *
 * Legge in input un file codificato ASCII e conta quante vocali,
 * consonanti, numeri e spazi ci sono, scrivendo il riepilogo in un file.
 *
 * Il nome del file è letto da riga di comando tramite argv.
 *
 * Il riepilogo contiene:
 * 	- Numero di vocali, consonanti, numeri e spazi
 * 	- Per ognuna delle precedenti categorie, quante volte
 * 	  ogni carattere è presente
 *
 * Inoltre, stampa in 3 file separati le vocali, consonanti e i numeri che trova.
 */

#include <stdio.h>

/* Check if a given char is a vowel */
int is_vowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
		return 1;
	return 0;
}

/* Check if a given char is a space */
int is_space(char c)
{
	if (c == ' ')
		return 1;
	return 0;
}

/* Check if a given char is a consonant.
 * This check needs two conditions and both must be true:
 * 	a. the char is a letter (uppercase or lowercase)
 * 	b. the char isn't a vowel
 */
int is_consonant(char c)
{
	if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) && !is_vowel(c))
		return 1;
	return 0;
}

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}

int main(int argc, char *argv[])
{
	FILE *input;
	FILE *o_summary = fopen("riepilogo.txt", "w");
	FILE *o_vowels = fopen("vocali.txt", "w");
	FILE *o_consonants = fopen("consonanti.txt", "w");
	FILE *o_digits = fopen("cifre.txt", "w");

	char line[100];
	char *filename;

	/* To count the occurrences of each character, we use an array of counters,
	 * each one associated with the numerically corresponding ASCII key.
	 * e.g. ascii[97] is 'a', ascii[98] is 'b' and so on...
	 *
	 * Note: ASCII table itself is 128-char long, I don't account for any
	 * extended character set.
	 */
	int ascii[128];
	int i;
	int n_vowels = 0;
	int n_spaces = 0;
	int n_consonants = 0;
	int n_digits = 0;

	/* Set ascii[] values to 0 */
	for(i = 0; i < 127; i++) {
		ascii[i] = 0;
	}

	/* Read the filename from argv[1] (if any) */
	if (argc > 1) {
		filename = argv[1];
		input = fopen(filename, "r");
		if(!input)
			return -1;
	} else {
		input = fopen("input.txt", "r");
	}

	while (fgets(line, 100, input)){
		i = 0;
		while (line[i] != '\0'){
			if ((unsigned char) line[i] <= 127) {
				/* Increment the counter associated with the currently read char.
				 * (unsigned char) is a double-check for robustness, since we
				 * already know line[i] is between 0 and 127.
				 */
				ascii[(unsigned char) line[i]]++;

				if (is_vowel(line[i])) {
					fprintf(o_vowels, "%c", line[i]);
					n_vowels++;
				} else if (is_space(line[i])) {
					n_spaces++;
				} else if (is_consonant(line[i])) {
					fprintf(o_consonants, "%c", line[i]);
					n_consonants++;
				} else if (is_digit(line[i])) {
					fprintf(o_digits, "%c", line[i]);
					n_digits++;
				}
			}
			i++;
		}
	}
	puts("foo");
	fprintf(o_summary, "Totale: %i\nVocali: %i\nSpazi: %i\nConsonanti: %i\nCifre: %d\n\n",
			n_vowels + n_spaces + n_consonants + n_digits, n_vowels, n_spaces, n_consonants, n_digits);

	fprintf(o_summary, "Conteggio dei caratteri (simboli inclusi):\n");

	/* Here we exclude obviously uninteresting key ranges
	 * (symbols, newlines, unprintable characters...) */
	for (i = 33; i < 127; i++) {
		if (ascii[i] > 0)
			fprintf(o_summary, "%c -> %i\n", (char) i, ascii[i]);
	}

	fclose(input);
	fclose(o_summary);
	fclose(o_vowels);
	fclose(o_consonants);
	fclose(o_digits);
	return 0;
}
