/*Fare un programma che prende in input: nome, cognome, numero di matricola, numero di esami conseguiti e voto
*dell'ultimo esame, devono essere stampati su un file, poi chiedi all'utente se è laureato: se si esci, se no
*chiedi se ha conseguito un altro esame: se si incrementa il numero degli esami svolti se no esci*/

#include <stdio.h>

struct student{
	char name[20];
	char surname[20];
	int identif_n;
	int n_exams;
	int mark;
};

int main ()
{
	struct student s; /* Declare a struct of type student named s */

	char n;
	n = 'a';
	FILE *output = fopen("output.txt", "w");

	printf("Input the following variables: name:\n");
	scanf("%19s", s.name);
	printf("surname:\n");
	scanf("%19s", s.surname);
	printf("identification number:\n");
	scanf("%i", &s.identif_n);
	printf("exams number:\n");
	scanf("%i", &s.n_exams);
	printf("last exam mark's:\n");
	scanf("%i", &s.mark);

	fprintf(output,"Name:%s\n, Surname:%s\n, identificatio number:%i\n, exams number:%i\n, last exam mark's:%i\n",
	s.name, s.surname, s.identif_n, s.n_exams, s.mark);

	printf("Are you graduate?"); /* This is ok... I think... */
	scanf("%c", &n);


	while (n != 'y') { {
		printf("have you done other exams? ");
		scanf("%c", &n);
		if (n == 'y')
			s.n_exam++;
	}
	fclose(output);
	return 0;
}

