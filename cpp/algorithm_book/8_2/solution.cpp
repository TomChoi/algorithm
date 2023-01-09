#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool solve(string& wild, string& file, int i, int j) {
    
    if(wild.size() == i) {
        if(file.size() <= j) {
            return true;
        } else {
            return false;
        }
    }

    if (wild[i] == '*') {
        if(i+1 == wild.size())
            return true;
        while(j<file.size()) {
            j++;
            if(file[j] == wild[i+1])
                return solve(wild, file, ++i, j);
        }
    } else if(wild[i] != '?') {
        if(wild[i] != file[j]) return false;
         ++i; ++j;
    }
    return solve(wild, file, i, j);
}

vector<string> solution(string& wild, vector<string>& files) {
    vector<string> ret;

    for(string& file: files) {
        if(solve(wild, file, 0, 0))
            ret.push_back(file);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    int q;
    cin>>q;
    while(q--) {
        string wild;
        cin>>wild;
        int n;
        cin>>n;
        vector<string> files(n);
        for(int i=0; i<n; ++i)
            cin>>files[i];
        vector<string> ret = solution(wild, files);
        for(string s: ret) {
            cout<<s<<"\n";
        }

    }

    return 0;
}
