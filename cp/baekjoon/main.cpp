#include <iostream>

using namespace std;
typedef long long ll;

ll N=31;
ll D=1234567891;
ll hashing(string &s) {
    ll res=0;
    ll sz=s.length();
    ll mul=1;
    for(ll i=0; i<sz; ++i) {
        res+=(s[i]-'a'+1)*mul%D;
        mul*=N;
        mul%=D;
    }
    return res%D;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    string s;
    cin>>n>>s;
    ll sz=s.length();
    printf("%lld\n", hashing(s));
    return 0;
}
