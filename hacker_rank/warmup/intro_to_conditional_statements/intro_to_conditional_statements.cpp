#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    if (n%2) {
        cout<<"Weird"<<"\n";
    } else {
        if (n >= 2 && n <= 5) {
            cout<<"Not Weird"<<"\n";
        } else if (n >= 6 && n <= 20) {
            cout<<"Weird"<<"\n";
        } else if (n > 20) {
            cout<<"Not Weird"<<"\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    solve(n);
    return 0;
}
