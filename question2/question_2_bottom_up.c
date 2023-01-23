#include <stdio.h>
#include <stdlib.h>

/*
* Fibonacci - function to return the fibonacci sequnece in the given order
* Get_Random - Function to get a random integer number 
* main - Function to compute the fibonnaci sequence
* @n- integer number to get the fibonacci sequence for
*
* Build a cache representing the Fibonacci sequence.
*/

int Fibonacci(int n) {
    int i;
    int* fibo = (int*) malloc(n * sizeof(int));
    fibo[0] = 0;
    fibo[1] = 1;
    fibo[2] = 2;
    for (i = 3; i <= n; ++i) {
        fibo[i] = fibo[i-3] + fibo[i-2];
    }
    return fibo[n];
}


int Get_Random() {
    int lower = 1, upper = 10;
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;    
}   

int main (void) {
    int count = 4;
    int j;
    for (j=0; j < count; j++) {
        /* For loop to print 4 iterations of n different fib numbers*/
        int n = Get_Random();
        printf("The Fibonacci sequence of %d is %d\n", n, Fibonacci(n));
    }
    
    return 0;
}

