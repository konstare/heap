#include "heap.h"
#include <stdbool.h>
#include <stdio.h>

bool compare_fn(void *a, void *b){
  return *(int *)a > *(int *)b;
}

int main(int argc, const char *argv[]) {
  (void)argc;
  (void)argv;
  
  int *x = NULL; /* initialize to NULL, replace *int* with any type you want */
  HEAP(int) y = NULL;  /*This is equivalent initialization */

  HEAP_INIT(x, compare_fn);

  /*Insert values into the HEAP*/
  HEAP_INSERT(x, 2);
  HEAP_INSERT(x, 10);
  HEAP_INSERT(x, 1);
  HEAP_INSERT(x, 20);
  HEAP_INSERT(x, 5);
  HEAP_INSERT(x, 50);


  /*Will not compile
  HEAP_INSERT(x, "d");
  */
  
  
  /*Get root of the heap*/
  int *root = HEAP_ROOT(x);
  /*Will not compile
  char *root = HEAP_ROOT(x);
  */
  printf("%d\n", *root);

  /*Remove root*/
  HEAP_POP(x);

  /* standard [] lookup of values */
  for(size_t i=0; i< HEAP_SIZE(x); i++){
    printf("%d ", x[i]);
  }
  
  /* free memory */
  HEAP_FREE(x);
  HEAP_FREE(y);
}
