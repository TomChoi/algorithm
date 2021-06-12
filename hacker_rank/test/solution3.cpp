#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> a={1,4,2,6,0};
    auto it=min_element(a.begin(), a.end());
    int idx=it-a.begin();
    cout<<"index: "<<idx<<"\t value: "<<*it<<endl;

    return 0;
}
