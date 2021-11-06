#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a,b,v;
    cin>>a>>b>>v;
    cout<<(int)ceil((v-a) / (float)(a-b)) + 1<<endl;
    cout<<(int)(999999900.0 / 1.0) + 1<<endl;
    return 0;
}
