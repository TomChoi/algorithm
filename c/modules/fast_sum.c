#include <stdio.h>

int fastSum(int n) {
    if(n == 1) return 1;
    if(n % 2 == 1) return fastSum(n-1) + n;
    return 2*fastSum(n/2) + (n/2) * (n/2);
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", fastSum(n));

    return 0;
}
