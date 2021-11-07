#include <iostream>

using namespace std;

int main() {
    int x; 
    cin>>x;

    int n=0,sum=0;
    while(sum < x) {
        sum += ++n;
    }

    int r = sum-x;
    if(n%2 == 0) {
        cout<<n-r<<"/"<<1+r<<endl;
    } else {
        cout<<1+r<<"/"<<n-r<<endl;
    }

    return 0;
}
