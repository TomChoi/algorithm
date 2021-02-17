#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

void solve() {
    int i=3;
    double d=1.2;
    string s="Tom ";

    int i2;
    double d2;
    string s2;

    cin>>i2>>d2;
    cin.ignore();
    getline(cin, s2);

    cout<<i+i2<<"\n";
    cout<<fixed<<setprecision(1)<<d+d2<<"\n";
    cout<<s<<s2<<"\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}

