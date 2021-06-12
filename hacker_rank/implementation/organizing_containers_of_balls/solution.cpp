#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

std::string solve(std::vector<std::vector<int>> container) {
    int sz=container.size();
    std::vector<std::vector<int>> ck(2);
    for(int i=0; i<2; ++i)
        ck[i].resize(sz);

    for(int i=0; i<sz; ++i) {
        for(int j=0; j<sz; ++j) {
            ck[0][i]+=container[i][j];
        }
    }

    for(int i=0; i<sz; ++i) {
        for(int j=0; j<sz; ++j) {
            ck[1][i]+=container[j][i];
        }
    }
    
    for(int i=0; i<2; ++i)
        std::sort(ck[i].begin(), ck[i].end());

    for(int i=0; i<sz; ++i) {
        if (ck[0][i]!=ck[1][i])
            return "Impossible";
    }

    return "Possible";
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int q;
    std::cin>>q;
    
    std::vector<int> n(q);
    std::vector<std::vector<std::vector<int>>> m(q);

    for(int i=0; i<q; ++i) {
        std::cin>>n[i];
        m[i].resize(n[i]);
        for(int j=0; j<n[i]; ++j) {
            m[i][j].resize(n[i]);
            for(int k=0; k<n[i]; ++k) {
                std::cin>>m[i][j][k];
            }
        }
        std::string ans=solve(m[i]);
        std::cout<<ans<<"\n";
    }

    return 0;
}
