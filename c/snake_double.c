/* snake_double.c
 * Author: Roberto D'Auria
 *
 * Same as snake.c, but with a double-linked list
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 40

typedef struct snake_piece {
	char *name;
	char *color;
	struct snake_piece *prev;
	struct snake_piece *next;
} snake_piece;

void display(snake_piece *starting_piece)
{
	snake_piece *i = starting_piece;

	while (i) {
		printf("Name: %s\nColor: %s\nPrev: %p\nNext: %p", i->name, i->color, i->prev, i->next);
		printf("\n--------------------------\n");
		i = i->next;
	}
}

snake_piece *create(char *name, char *color)
{
	snake_piece *new_piece = malloc(sizeof(snake_piece));
	new_piece->name = strdup(name);
	new_piece->color = strdup(color);
	new_piece->prev = NULL;
	new_piece->next = NULL;
	return new_piece;
}

void free_all(snake_piece *starting_piece)
{
	snake_piece *i = starting_piece;
	snake_piece *temp = NULL;
	while (i) {
		temp = i;
		i = i->next;
		free(temp->name);
		free(temp->color);
		free(temp);
	}
}

int main()
{
	char name[BUFSIZE];
	char color[BUFSIZE];

	snake_piece *first = NULL;
	snake_piece *old_piece = NULL;
	snake_piece *new_piece = NULL;

	do {
		puts("Insert new piece data, or \"tail\" as the name to complete the snake:");
		fgets(name, BUFSIZE, stdin);
		fgets(color, BUFSIZE, stdin);

		name[strlen(name)-1] = '\0';
		color[strlen(color)-1] = '\0';
		new_piece = create(name, color);
		printf("Created new piece, addr %p\n", new_piece);

		if (old_piece) {    /* at first iteration there is no old_piece */
			printf("Linking old_piece to %p\n", new_piece);
			printf("Linking new_piece to %p\n", old_piece);
			old_piece->next = new_piece;
			new_piece->prev = old_piece;
		} else {
			printf("First iteration, no linking, %p is the first piece\n", new_piece);
			first = new_piece;
		}

		old_piece = new_piece;
	} while (strcmp(name, "tail"));

	display(first);
	free_all(first);

	return 0;
}


