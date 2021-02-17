#include <bits/stdc++.h>

using namespace std;

int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
int day=256;

string solve(int year) {
    if (year >= 1700 && year<=1917) {
        if (!(year%4)) {
            return "12.09."+to_string(year);
        } else {
            return "13.09."+to_string(year);
        }
    } else {
        if (!(year%400) || (!(year%4) && (year%100))) {
            return "12.09."+to_string(year);
        } else {
            return "13.09."+to_string(year);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int year;
    cin>>year;
    string ans=solve(year);
    cout<<ans<<"\n";
    return 0;
}
