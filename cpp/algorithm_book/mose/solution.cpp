#include <iostream>
#include <vector>

using namespace std;

void generator(int n, int m, string s) {
    if(n==0 && m==0) {
        cout<<s<<endl;
        return; 
    }

    if(n != 0) {
        generator(n-1, m, s + '-');
    }
    if(m != 0) {
        generator(n, m-1, s + 'o');
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;

    string s;
    generator(n, m, s);
    
    return 0;
}
