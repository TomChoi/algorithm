#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a,b;
    cin>>a>>b;

    int res=0,c=0;
    while(b) {
        int n = b%10;
        b /= 10;
        int i = a*n;
        cout<<i<<endl;
        res+=i*pow(10,c++);
    }
    cout<<res<<endl;

    return 0;
}
