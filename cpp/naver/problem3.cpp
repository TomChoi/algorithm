#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solution(vector<int>& arr) {
    stack<int> ms;
    ms.push(arr[0]);
    for(int i=1; i<arr.size(); ++i) {
        if(ms.top() < arr[i]) {
            ms.push(arr[i]);
        } else {
            int temp = -1;
            while(!ms.empty() && ms.top() > arr[i]) {
                temp = max(temp, ms.top());
                ms.pop();
            }
            ms.push(temp);
        }
    }
    return ms.size();
}

int main() {

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; ++i) {
        cin>>arr[i];
    }

    cout<<solution(arr)<<endl;

    return 0;
}
