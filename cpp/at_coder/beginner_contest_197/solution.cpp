#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;

    string ans = s.substr(1) + s[0];

    cout<<ans<<"\n";

    return 0;
}

