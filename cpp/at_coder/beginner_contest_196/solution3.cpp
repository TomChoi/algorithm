#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;
    
    int len = s.length();
    int ans = 0;
    if (len % 2 == 0) {
        string s1 = s.substr(0, len/2);
        string s2 = s.substr(len/2, len);
        ans = stoi(s1) - 1;
        if(s1 < s2)
            ans++;
    } else {
        ans = pow(10,len / 2) - 1;
    }
    
    cout<<ans<<endl;
    
    return 0;
}
