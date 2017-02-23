#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::chrono::time_point;
using std::chrono::duration;
using std::chrono::high_resolution_clock;

// Fibonacci Calculation without Memoization
int fib(int n) {
    if (n <= 0) return 0;
    else if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

// Fibonacci Calculation
void allFib(int n) {
    cout << "\nThese are the first " << n << " Fibonacci numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cout << fib(i) << (" ");
    }
    cout << endl;
}

// Fibonacci Calculation with Memoization
long long int fibwithMem(int n, vector<long long int> &memoizedarray) {
    if (n <= 0) return 0;
    else if (n == 1) return 1;
    return fibwithMem(n - 1, memoizedarray) + memoizedarray[n - 2];
}

// Fibonacci Calculation
void allFibwithMem(int fibnum, vector<long long int> &memoizedarray) {
    long long int numFib;
    char ansOut;
    for (int i = 0; i < fibnum; i++) {
        memoizedarray[i] = fibwithMem(i, memoizedarray);
    }
    cout << "Would you like a single number or the entire list?\nEnter 's' for single or 'l' for list: ";
    cin >> ansOut;
    if (ansOut == 'S' || ansOut == 's') {
        numFib = memoizedarray[fibnum - 1];
        cout << "The Fibonacci number for " << fibnum << " is " << numFib << endl;
    }
    else if (ansOut == 'L' || ansOut == 'l') {
    cout << "\nThese are the first " << fibnum << " Fibonacci numbers:" << endl;
        for (int i = 0; i < fibnum; i++) {
            cout << memoizedarray[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "You have not entered either a 's' or a 'l'. Bye-bye." << endl;
    }
}

int main() {
    unsigned int fibnum;
    char ans, ansOut;
    time_point<high_resolution_clock> start, finish;
    std::chrono::duration<double> elapsed;
    cout << "\nEnter the maximum number for the Fibonacci calculation: ";
    cin >> fibnum;
    cout << "Would you like to run the calculation with Memoization?: ";
    cin >> ans;

    // Calculation to proceed with Memoization
    if (ans == 'Y' || ans == 'y') {
        vector <long long int> memoizedarray(fibnum);

        start = high_resolution_clock::now();
        allFibwithMem(fibnum, memoizedarray);
        finish = high_resolution_clock::now();
        elapsed = finish - start;
        cout << "\nThe elapsed calculation time utilizing Memoization is " << elapsed.count() << " seconds."
                 << endl;
    }
    // Calculation to proceed without Memoization
    else {
        start = high_resolution_clock::now();
        allFib(fibnum);
        finish = high_resolution_clock::now();
        elapsed = finish - start;
        cout << "\nThe elapsed calculation time without Memoization is " << elapsed.count() << " seconds." << endl;
    }
    return 0;
}
