#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct dynamic_array_struct {
  int* data;
  size_t capacity;
  size_t size;
} vector;

void build_indices(int* index, int* trans, int n, int m);

void print_pretty_matrix(int* const data_vec, int* index, int* trans,  int n, int m, int transpose);


double serial_dot_product(int* const data_vec, int* index, int* trans, int size);

double serial_vec_norm(int* const data_vec, int* index, int* trans, int size);


#endif
