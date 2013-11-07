/* Author: Roberto D'Auria
 * Implementation of the (Extended) Euclidean Algorithm
 *
 * euclide.h
 */

#ifndef EUCLIDE_H
#define EUCLIDE_H

int MCD(int n1, int n2, int mem_table[3][5], int *x, int *y);
void shift_up(int mem_table[3][5]);
void print_row(int n, int mem_table[3][5]);

#endif