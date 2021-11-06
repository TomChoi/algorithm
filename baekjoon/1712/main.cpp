#include <iostream>

using namespace std;

int main() {
    int a,b,c;
    cin>>a>>b>>c;

    int profit = c-b;
    if(profit <= 0) {
        cout<<"-1"<<endl;
    } else {
        cout<<(a / profit) + 1<<endl;
    }
    return 0;
}
