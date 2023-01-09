#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

vector<string> cache;

string generateDragonCurve(int n) {
    string& ans = cache[n];
    if(!ans.empty()) return ans;

    if(n == 0) {
        ans = "FX";
        return ans;
    }

    for(int i=n-1; i>0; --i) {
        ans += "+" + generateDragonCurve(i);
    }

    if(n % 2 == 0) {
        ans += "+" + generateDragonCurve(0) + "-YF";
    } else {
        ans += "-" + generateDragonCurve(0) + "+YF";
    }

    ans.erase(ans.begin());
    return ans;
}

string solution(int n, int p, int l) {
    int num = 2;
    for(int i=1; i<n; ++i) {
        num = 2 * num + 1;
        if(num + 2 > p) {
            p = num;
            break;
        }
    }
    
    return generateDragonCurve(n).substr(p-1, l);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin>>q;

    while(q--) {
        int n, p, l;
        cin>>n>>p>>l;

        cache.resize(n+1); 
        for(string& s: cache)
            s="";

        string ans = solution(n, p, l);
        cout<<ans<<"\n";
    }

    return 0;
}
