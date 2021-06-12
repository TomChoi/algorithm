#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;
int good_solution(vector<vector<string>> clothes) {
    int ans=1;
    unordered_map<string, int> m;
    for(c: clothes) {
        m[c[1]]++;
    }

    for(auto e: m) {
        ans*=(e.second+1);
    }
    return ans-1;
}

int solution(vector<vector<string>> clothes) {
    int ans=0;
    unordered_map<string, int> m;
    for(auto c: clothes) {
        m[c[1]]++;
        ans++;
    }
    vector<int> v;
    for(auto e: m) {
        v.push_back(e.second);
    }

    int g=v.size();
    int c=2;
    while(c<=g) {
        vector<int> p(g-c,0); 
        for(int i=0; i<c; ++i) {
            p.push_back(1);
        }
        do {
            int sum=1;
            for(int i=0; i<g; ++i) {
                if(p[i]) {
                     sum*=v[i];
                }
            }
            ans+=sum;
        } while(next_permutation(p.begin(), p.end()));
        c++;
    }

    return ans;
}

vector<string> string_spliter(string s, char div) {
    vector<string> res;
    istringstream ss(s);
    string buf;

    while(getline(ss, buf, div)) {
        res.push_back(buf);
    }
    return res;
}

vector<vector<string>> parsing_input(string s) {
    vector<vector<string>> ans;
    s=s.substr(1,s.length()-2);
    int sz=s.length();
    int i=0, ii=0;
    while(i<sz) {
        if(s[i++]=='[') {
            ans.push_back(vector<string>());
            string ss="";
            while(s[i]!=']') {
                if(s[i]!='"' && s[i]!=',') {
                    ss+=s[i];
                }
                i++;
            }
            vector<string> v=string_spliter(ss, ' ');
            for(string e: v) {
                ans[ii].push_back(e);
            }
            ii++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    getline(cin, s);
    auto in=parsing_input(s);

    int res=solution(in);
    cout<<res<<"\n";
    
    return 0;
}
