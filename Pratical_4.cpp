#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

unsigned long long factorialIterative(int n)
{
    unsigned long long fact = 1;

    for (int i = 1; i <= n; i++)
        fact *= i;

    return fact;
}

unsigned long long factorialRecursive(int n)
{
    if (n <= 1)
        return 1;

    return n * factorialRecursive(n - 1);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    auto start1 = high_resolution_clock::now();
    unsigned long long result1 = factorialIterative(n);
    auto stop1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    unsigned long long result2 = factorialRecursive(n);
    auto stop2 = high_resolution_clock::now();

    auto time1 = duration_cast<nanoseconds>(stop1 - start1).count();
    auto time2 = duration_cast<nanoseconds>(stop2 - start2).count();

    cout << "\nIterative Factorial = " << result1 << endl;
    cout << "Iterative Time = " << time1 << " nanoseconds" << endl;

    cout << "\nRecursive Factorial = " << result2 << endl;
    cout << "Recursive Time = " << time2 << " nanoseconds" << endl;

    return 0;
}
