#include <iostream>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int h,w,n;
        cin>>h>>w>>n;
        int hn = n%h == 0 ? h : n%h;
        int wn = hn == h ? n/h : n/h+1;

        if(wn < 10) {
            cout<<hn<<"0"<<wn<<endl;
        } else {
            cout<<hn<<wn<<endl;
        }
    }
    return 0;
}

