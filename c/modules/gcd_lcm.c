#include <stdio.h>

int gcd(int a, int b)
{
    if(a == 0)
        return b;
    return gcd(b % a, a);
}

// 1. GCD를 이용한 배열 전체에서 gcd 찾기!
int findGCD(int arr[], int n) 
{
    int result = arr[0];
    for(int i=1; i<n; ++i) {
        result = gcd(arr[i], result);
        
        // 어느 두 요소의 gcd가 1이라는 의미는 약수가 없다는 의미로 
        // 전체 요소의 공통 약수를 구하는 것이기 때문에 이후 과정을 필요 없다.
        if(result == 1) {
            return 1;
        }
    }
    return result;
}

// 2. GCD를 이용해 최소공배수! LCM(Least Common Multiple) 구하기
// 관련 내용 책 p.69
int lcm(int a, int b)
{
    return a*(b/gcd(a,b));
}

int findLCM(int arr[], int n)
{
    int ans = arr[0];
    for(int i=1; i<n; ++i)
        ans = lcm(ans, arr[i]);

    return ans;
}

int main() 
{
    int arr[] = {2, 4, 6, 8, 16};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Input array\n");
    for(int i=0; i<n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int gcd = findGCD(arr, n);
    printf("GCD: %d\n", gcd);

    int lcm = findLCM(arr, n);
    printf("LCM: %d\n", lcm);

    return 0;
}
    
