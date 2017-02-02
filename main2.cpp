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

int fib(int n) {
    if (n <= 0) return 0;
    else if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

void allFib(int n) {
    cout << "\nThese are the first " << n << " Fibonacci numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cout << fib(i) << (" ");
    }
    cout << endl;
}

int fibwithMem(int n, vector<int> &memoizedarray) {
    if (n <= 0) return 0;
    else if (n == 1) return 1;
    return fibwithMem(n - 1, memoizedarray) + memoizedarray[n - 2];
}

void allFibwithMem(int n, vector<int> &memoizedarray) {
    for (int i = 0; i < n; i++) {
        memoizedarray[i] = fibwithMem(i, memoizedarray);
    }
    cout << "\nThese are the first " << n << " Fibonacci numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cout << memoizedarray[i] << " ";
    }
    cout << endl;
}

int main() {
    unsigned int fibnum;
    char ans;
    time_point<high_resolution_clock> start, finish;
    std::chrono::duration<double> elapsed;
    cout << "\nEnter the maximum number for the Fibonacci calculation: ";
    cin >> fibnum;
    cout << "Would you like to run the calculation with Memoization?: ";
    cin >> ans;

    if (ans == 'Y' || ans == 'y') {
        vector <int> memoizedarray(fibnum);
        start = high_resolution_clock::now();
        allFibwithMem(fibnum, memoizedarray);
        finish = high_resolution_clock::now();
        elapsed = finish - start;
        cout << "\nThe elapsed calculation time utilizing Memoization is " << elapsed.count() << " seconds." << endl;
    }
    else {
        start = high_resolution_clock::now();
        allFib(fibnum);
        finish = high_resolution_clock::now();
        elapsed = finish - start;
        cout << "\nThe elapsed calculation time without Memoization is " << elapsed.count() << " seconds." << endl;
    }
    return 0;
}
