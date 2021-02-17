#include <bits/stdc++.h>
using namespace std;

string solve(string s) {
    string ans="";

    int hh = stoi(s.substr(0,s.find(":")));
    int mm = stoi(s.substr(s.find(":")+1,s.find(":", s.find(":")+1)));
    int ss = stoi(s.substr(s.rfind(":")+1, s.rfind(":")+3));
    string t = s.substr(s.length()-2, s.length()-1);

    if (t == "PM") {
        if (hh != 12)
            hh += 12;
    } else {
        if (hh == 12)
            hh = 0;
    }
    
    if (hh < 10) 
        ans += "0" + to_string(hh);
    else 
        ans += to_string(hh);
    ans += ":";
    if (mm < 10)
        ans += "0" + to_string(mm);
    else
        ans += to_string(mm);
    ans += ":";
    if (ss < 10)
        ans += "0" + to_string(ss);
    else
        ans += to_string(ss);

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;

    string ans=solve(s);
    cout<<ans<<"\n";

    return 0;
}
