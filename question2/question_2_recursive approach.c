#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
* Fibonacci  -Recursive function to return the fibonacci sequnece in the given order
* Get_Random - Function to get a random integer number 
* main - Function to compute the fibonnaci sequence
* @n- integer number to get the fibonacci sequence for
*/

int Fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        return Fibonacci(n-3) + Fibonacci(n-2);
    }
}

int Get_Random() {
    int lower = 1, upper = 10;
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;    
}   

int main (void) {
    
    int count = 5;
    int i;
    for (i = 0; i < count; i++) {
        int n = Get_Random();
        printf("The Fibonacci sequence of %d is %d\n", n, Fibonacci(n));
    }
    return 0;
}

