#include <cmath>
#include <iostream>

bool isPrime(int n) {
    // corner cases
    if (n <= 1)
        return false;

    int k=sqrt(n);
    if (int i=2; i<=k; ++i) {
        if(n%i == 0) return false;
    }

    return true;
}
