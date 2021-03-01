#include <string>
#include <iostream>

int solve(std::string name) {
    int ans=0;
    int i=0,sz=name.size();
    while(true) {
        if(name[i] != 'A') {
            ans += std::min(name[i]-'A', 'Z'-name[i]+1);
            name[i]='A';
        }
        int l=i,r=i,lc=0,rc=0;
        do {
            if(--l<0) l=sz-1;
            lc++;
            if(name[l] != 'A') break;
        } while(l != i);

        do {
            if(++r>=sz) r=0;
            rc++;
            if(name[r] != 'A') break;
        } while(r != i);

        if(l == i || r == i)
            break;

        if(lc>rc) {
            i=r;
            ans+=rc;
        } else {
            i=l;
            ans+=lc;
        }
    }
    return ans;
}


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string s;
    std::cin>>s;
    int ans=solve(s);
    std::cout<<ans<<"\n";

    return 0;
}

