#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

unsigned fact(unsigned n, unsigned res = 1);
unsigned fib(unsigned n, unsigned a = 0, unsigned b = 1);
unsigned mult(unsigned x, unsigned y, unsigned res = 0);
unsigned power(unsigned x, unsigned y, unsigned res = 1);
unsigned product(unsigned x, unsigned y, unsigned p = 1);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls various recursive functions that can be
 * optimized using tail recursion.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // try a ridiculous case that won't work without tail recursion
    cout << "6 * 123000 = " << mult(6, 123000) << endl;
    
    // these functions can't demonstrate the usefulness of tail recursion
    // due to data type overflow, but still, good practice
    cout << "3 ^ 10 = " << power(3, 10) << endl;
    cout << "8 * 9 * ... * 15 = " << product(8, 15) << endl;
    cout << "10! = " << fact(10) << endl;

    // without tail recursion, this next call is going to take a while
    cout << "50th Fibonacci number is " << fib(50) << endl;

    // terminate
    return 0;
}

/*******************************************************************************
 * Function definitions below are NOT tail recursive!
 * TODO: make them tail recursive :)
*******************************************************************************/

unsigned fact(unsigned n, unsigned res) {
    // base cases (combined)
    if (n <= 1) {
        return res;
    }

    // recursive case
    return fact(n - 1, res * n);
}

unsigned fib(unsigned n, unsigned a, unsigned b) {
    // base case 1
    if (n == 0) {
        return a;
    }

    // base case 2
    else if (n == 1) {
        return b;
    }

    // recursive case
    return fib(n - 1, b, a + b);        // a+b is the next fibonacci number and b is the current fibonacci number so we pass those as the new a and b respectively for the next call to the func
}

unsigned mult(unsigned x, unsigned y, unsigned res) {
    // base case
    if (y == 0) {
        return res;
    }

    // recursive case
    return mult(x, y - 1, res + x);
}

unsigned power(unsigned x, unsigned y, unsigned res) {
    // base case
    if (y == 0) {
        return res;
    }

    // recursive case
    return power(x, y - 1, res*x);
}

unsigned product(unsigned x, unsigned y, unsigned p) {
    // base case
    if (x == y) {
        return p;
    }

    // recursive case
    return product(x + 1, y, p*x);;
}
