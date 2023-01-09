#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> spliter(string s, char divider) {
    vector<string> ans;
    istringstream ss(s);
    string buffer;
    while(getline(ss, buffer, divider)) {
        ans.push_back(buffer);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> a={"TOM,1234,kkda,1231","G,1111,zzzzz,3333"};
    
    for(string s: a){
        vector<string> ans=spliter(s,',');
        for(string e: ans)
            cout<<e<<endl;
    }

    return 0;
}
