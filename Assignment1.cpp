#include <iostream>
using namespace std;

// Recursive Fibonacci
int recFib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    // if(n<=1) return 1;
    return recFib(n - 1) + recFib(n - 2);
}

// Iterative Fibonacci
int itrFib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1, c;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<a+b<<endl;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        if(i>2) cout<<c<<" ";
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Recursive Fib(" << n << ") = " << recFib(n) << endl;
    cout << "Iterative Fib(" << n << ") = " << itrFib(n) << endl;

    return 0;
}
