#include <iostream>
#include <map>
#include <algorithm>

bool comp(std::pair<int,int> a, std::pair<int,int> b) {
    return a.second>b.second;
}

int main() {
    std::map<int, int, std::greater<int>> m;
    for(int i=0; i<3; ++i) {
        m[i]=i+1;
    }

    std::sort(m.begin(), m.end(), comp);
    
    for(std::pair<int,int> it: m) {
        std::cout<<it.first<<" "<<it.second<<std::endl;
    }

    return 0;
}
