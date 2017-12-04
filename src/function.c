#include "function.h"

int vector_init(vector* v, size_t init_capacity)
{
  v->data = malloc(init_capacity * sizeof(int));
  if (!v->data) return -1;

  v->size = 0;
  v->capacity = init_capacity;

  return 0; /* success */
}

void build_indices(int* index, int* trans, int n, int m){
	for (int i=0; i < m; i++){
		for (int j=0; j < n; j++){
			index[i*n+j] = trans[j*m+i] = i*n+j;
		}
	}
}

void print_pretty_matrix(int* const data_vec, int* index, int* trans, int n, int m, int transpose){
  if(transpose == 0){
  	for(int i=0; i<m*n; i++){
      if(i % n == 0){
        printf("\n");
        }
        printf("%i\t", data_vec[index[i]]);
      }

      printf("\n");
    }
  else
    {
      for(int i = 0; i<m*n; i++){
        if(i % m == 0){
          printf("\n");
        }
        printf("%i\t", data_vec[trans[i]]);
        }
        printf("\n");
    }
}

double serial_dot_product(int* const data_vec, int* index, int* trans, int size){
  float temp_total = 0;
  for(int i = 0; i<size; i++){
    temp_total+=data_vec[index[i]]*data_vec[trans[i]];
  }
  return temp_total;
}

double serial_vec_norm(int* const data_vec, int* index, int* trans, int size){
  return sqrt(serial_dot_product(data_vec, index, trans, size));
}
