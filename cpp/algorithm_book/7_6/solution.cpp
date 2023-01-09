#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(string star, string fan) {
    int ans=0;
    int diff = fan.size() - star.size();
    for(int i=0; i<=diff; ++i) {
        int pass = true;
        for(int j=0; j<star.size(); ++j) {
            if(star[j] == 'M' && fan[i+j] == 'M') {
                pass = false;
                break;
            }
        }
        if(pass) ans++;
    }

    return ans;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    while(n--) {
        string star, fan;
        cin>>star>>fan;
        cout<<solution(star, fan)<<"\n";
    }

    return 0;
}
