#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>

int fib(int n) {
    if (n > 45) {
        printf("n is too big to calculate fib n");
        return 0;   
    }
    if (n < 2) {
        return 1;
    }
    else {
        return fib(n-1) + fib(n-2);
    }
}

int is_prime(int n) {
    if (n % 2 == 0 && n != 2) {
        return 1;
    }
    else {
        for (int i = 3; i <= sqrt(n); i = i + 2) {
            if (n % i == 0) {
                return 1;
            } 
        }
    }
    return 0;
}

int* prime_factor(int n) {
    int *arr = malloc(10*sizeof(int));
    if (is_prime(n) == 0) {
        return &n;
    }
    else {
        int j = 0;
        int ten_mult = 0;
        while (n % 2 == 0) {
            if (j <= 9 + ten_mult*10)  {
                arr[j] = 2;
                j++;
            }
            else {
                arr = realloc(arr, 10*sizeof(int));
                ten_mult++;
                arr[j] = 2;
                j++;
            }
            n = n / 2;
        }
        for (int i = 3; i <= n; i=i+2) {
            while (n % i == 0) {
                if (j <= 9 + ten_mult*10) {
                    arr[j] = i;
                    j++;
                }
                else {
                    arr = realloc(arr, ten_mult*10*sizeof(int));
                    ten_mult++;
                    arr[j] = i;
                    j++;
                }
                n = n / i;
            }
        }
    }
    return arr;
}

void* fib_thread(void *arg) {
    int *r = malloc(sizeof(int));
    int n = *(int*)arg;
    *r = fib(n);
    return r;
}

void* is_prime_thread(void *arg) {
    int *r = malloc(sizeof(int));
    int n = *(int*)arg;
    *r = is_prime(n);
    return r;
}

void* prime_factor_thread(void *arg) {
    int *r = malloc(100*sizeof(int));
    int n = *(int*)arg;
    r = prime_factor(n);
    return r;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Please give excactly one argument!");
        return 1;
    }
    int n = atoi(argv[1]);
    printf("Your number is: %d\n", n);
    int *is_prime_p, *fib_p, *prime_factor_p;
    pthread_t is_prime_id, prime_factor_id, fib_id;
    pthread_create(&is_prime_id, NULL, is_prime_thread, &n);
    pthread_create(&fib_id, NULL, fib_thread, &n);
    pthread_create(&prime_factor_id, NULL, prime_factor_thread, &n);
    pthread_join(is_prime_id, (void**)&is_prime_p);
    pthread_join(fib_id, (void**)&fib_p);
    pthread_join(prime_factor_id, (void**)&prime_factor_p);
    if (*is_prime_p == 1) {
        printf("%d is not prime!\n", n);
    }
    else {
        printf("%d is prime!\n", n);
    }
    printf("fib of %d is: %d\n", n, *fib_p);
    if (is_prime(n) == 0) {
        printf("Prime factorization of n is: %d", n);
    }
    else {
        printf("Prime factorization of n is:\n");
        for (int i = 0; prime_factor_p[i] != NULL; i++) {
            if (i == 0) {
                printf("%d", prime_factor_p[i]);
            }
            else {
                printf("*%d", prime_factor_p[i]);
            }
        }
    }
}