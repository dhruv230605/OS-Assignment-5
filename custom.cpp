#include "simple-multithreader.h"
#include <assert.h>

int main(int argc, char** argv) {
  // Initialize problem size
  int numThread = argc > 1 ? atoi(argv[1]) : 4;
  int size = argc > 2 ? atoi(argv[2]) : 48000000;
  // Allocate vectors
  int* A = new int[size];
  int* B = new int[size];
  int* C = new int[size];
  // Initialize the vectors
  std::fill(A, A + size, 2);
  std::fill(B, B + size, 3);
  std::fill(C, C + size, 0);
  // Start the parallel multiplication of two vectors
  parallel_for(0, size, [&](int i) {
    C[i] = A[i] * B[i];
  }, numThread);
  // Verify the result vector
  for (int i = 0; i < size; i++) assert(C[i] == 6);
  printf("Multiplication Test Success\n");
  // Cleanup memory
  delete[] A;
  delete[] B;
  delete[] C;
  return 0;
}
