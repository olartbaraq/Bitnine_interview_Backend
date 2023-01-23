#include <stdio.h>
#include <stdlib.h>

/*
* Fibonacci - Cached-Array like function to return the fibonacci sequnece in the given order
* Get_Random - Function to get a random integer number 
* main - Function to compute the fibonnaci sequence
* @n- integer number to get the fibonacci sequence for
*
* Build a cache representing the Fibonacci sequence.
*/

#define MAX_N 10000
/* Declaration of an array to serve as a cache to hold fibonacci numbers of elements seen */
int memo[MAX_N + 1];

int Fibonacci(int n) {
    /* If the cache holds -1 at the required index, it has not yet been computed. */
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else if (memo[n] != -1) {
        return memo[n];
    } else {
        memo[n] = Fibonacci(n-3) + Fibonacci(n-2);
        return memo[n];
    }
}


int Get_Random() {
    int lower = 1, upper = 10;
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;    
}   

int main (void) {
    int count = 7;
    int i, j;
    for (i = 0; i <= MAX_N; i++) {
        /* Initialise an array of MAX_N elements, each element set to -1 */
        memo[i] = -1;
    }
    for (j=0; j < count; j++) {
        /* For loop to print 7 iterations of n different fib numbers*/
        int n = Get_Random();
        printf("The Fibonacci sequence of %d is %d\n", n, Fibonacci(n));
    }
    
    return 0;
}

