#include <iostream>

using namespace std;

int main() {
    int n, c=1, i=1;
    cin>>n;

    while(n > c) {
        c += 6*i++;
    }
    cout<<i<<endl;
    return 0;
}
