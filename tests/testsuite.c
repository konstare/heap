#include "test.h"
#include "../heap.h"

typedef struct{
  size_t len;
} Int_Wrapper;

bool compare(void *a, void *b){
  const Int_Wrapper *k1 = a;
  const Int_Wrapper *k2 = b;
  return k1->len > k2->len;
}

#define ARRAY_LENGTH(x)                                                        \
  ((sizeof(x) / sizeof(0 [x])) / ((size_t)(!(sizeof(x) % sizeof(0 [x])))))


TEST(HeapTest) {
  bool assert =true;
  const size_t input[] = {6, 4, 9, 7, 16, 21, 24, 16, 28, 24, 21, 11, 21, 4, 4, 7, 30, 9, 7, 19, 21, 18, 20, 8, 25, 24, 17, 30, 16, 27};
  const size_t answer[] = {30, 30, 28, 27, 25, 24, 24, 24, 21, 21, 21, 21, 20, 19, 18, 17, 16, 16, 16, 11, 9, 9, 8, 7, 7, 7, 6, 4, 4, 4};

  Int_Wrapper *result = NULL;
  HEAP_INIT(result, compare);

  
  for(size_t i=0; i< ARRAY_LENGTH(input); i++){
    Int_Wrapper res = {.len=input[i]};
    HEAP_INSERT(result, res);
  }
  
  for(size_t i=0; i<ARRAY_LENGTH(answer); i++){
    Int_Wrapper *res = HEAP_ROOT(result);
    assert &= res->len == answer[i];
    HEAP_POP(result);
  }
  HEAP_FREE(result);

  test_assert(assert);
}

TEST(HeapTest2) {
  bool assert =true;

  Int_Wrapper *result = NULL;
  HEAP_INIT(result, compare);

  size_t N=1000;
  for(size_t i=0; i< N; i++){
    Int_Wrapper res = {.len=i};
    HEAP_INSERT(result, res);
  }
  
  for(size_t i=0; i<N/2 ; i++){
    Int_Wrapper *res = HEAP_ROOT(result);
    assert &= res->len == N-i-1;
    HEAP_POP(result);
  }

  assert &= HEAP_SIZE(result) == N/2;
  
  for(size_t i=N/2; i< N; i++){
    Int_Wrapper res = {.len=i};
    HEAP_INSERT(result, res);
  }

  assert &= HEAP_SIZE(result) == N;
  
  for(size_t i=0; i<N ; i++){
    Int_Wrapper *res = HEAP_ROOT(result);
    assert &= res->len == N-i-1;
    HEAP_POP(result);
  }
  
  HEAP_FREE(result);

  
  test_assert(assert);

}

TEST(HeapTest3) {
  bool assert =true;
  const size_t input[] = {2, 10, 50, 20};
  const size_t answer[] = {50, 20, 10, 2};

  Int_Wrapper *result = NULL;
  HEAP_INIT(result, compare);

  
  for(size_t i=0; i< ARRAY_LENGTH(input); i++){
    Int_Wrapper res = {.len=input[i]};
    HEAP_INSERT(result, res);
  }
  
  for(size_t i=0; i<ARRAY_LENGTH(answer); i++){
    Int_Wrapper *res = HEAP_ROOT(result);
    assert &= res->len == answer[i];
    HEAP_POP(result);
  }
  HEAP_FREE(result);

  test_assert(assert);
}
