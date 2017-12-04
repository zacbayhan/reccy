#include "main.h"

int main(int argc, char *argv[]) {
    double dot;
    double norm;

    int debug_flag = 0;
    int size = argc-1;
    //place holder varables for matrix dimentions

    int n = 4; //height
    int m = 5; //base

    int num_proc = get_nprocs_conf();
    int proc_avail = get_nprocs();

    int* data_vec = (int*)calloc(argc, sizeof(int));
    int* index = (int*)calloc(size, sizeof(int));
    int* trans = (int*)calloc(size, sizeof(int));

    for(int i=0; i < size; i++){
      // converts command line arguments to int
      sscanf(argv[i+1], "%d", &data_vec[i]);
      //Output the argument string and its converted value (uncomment for debug)
      if(debug_flag == 1){
        printf( "\"%s\" -> %d\n", argv[i + 1], data_vec[i]);
      }
    }


    build_indices(index, trans, n, m);

    int transpose = 0;
    if(debug_flag == 1){
      printf("\n%i processors configured and %i processors available.\n\n", num_proc, proc_avail);
      for(int i=0; i<n*m; i++){
        printf("index[%i]: %i\t trans_index[%i]: %i\n", i, index[i], i, trans[i]);
      }
      printf("\n\n");
      for(int i =0; i<size; i++){
        printf("cli_data[%i]: %i\n", i, data_vec[trans[i]]);
      }
      print_pretty_matrix(data_vec, index, trans, n, m, transpose);
    }


    dot = serial_dot_product(data_vec, index, trans, size);

    norm = serial_dot_product(data_vec, index, trans, size);


    //free mem
    free(data_vec);
    free(index);
    free(trans);

    return 0;
}
