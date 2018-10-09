#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

bool Prime(int p);
int t;
int c = 0;
int a = 0;
int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("No arguments given");
  }
  else if (argc == 2) {
    int j = atoi(argv[1]);
    if (Prime(j)) {
      printf("Prime");
      return 0;
    }
    else {
      printf("Not prime, it is divisible by %d \n", t);
      return 0;
    }
  }
  else if (argc == 3) {
    int j = atoi(argv[2]);
    int *arr = malloc(j * sizeof(int));
    while (a < j) {
      c = c + 1;
      if (Prime(c)) {
	arr[a] = c;
	a = a + 1;
      }
    }
    for (int i = 0; i < j; i = i + 1) {
      printf("Prime number %d is %d \n", i+1, arr[i]);
    }
    free(arr);
    return 0;
  }
}

bool Prime(int p) {
  if (p == 0) {
    return false;
  }
  if (p == 1) {
    return false;
  }
  if (p == 2) {
    return true;
  }
  if (p % 2 == 0) {
    t = 2;
    return false;
  }
  for (int i = 3; i < p; i = i + 2) {
    if (p % i == 0) {
      t = i;
      return false;
    }
  }
  return true;
}
