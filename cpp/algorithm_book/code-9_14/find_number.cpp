#include <iostream>
#include <vector>

using namespace std;

const int N = 12;
int factorials[N];

int calcFactorial(int n) {
    int& ret = factorials[n];
    if(ret != -1) return ret;

    if(n == 0) return 1;
    ret = n * calcFactorial(n-1);

    return ret;
}

int getIndex(const vector<int>& X) {
    int ret = 0;
    for(int i = 0; i < X.size(); ++i) {
        int less = 0;
        for(int j = i + 1; j < X.size(); ++j) {
            if(X[j] < X[i]) ++less;
        }
        ret += factorials[X.size() - i - 1] * less;
    }
    return ret;
}

int main() {
    
    memset(factorials, -1, sizeof(factorials));
    calcFactorial(N-1);

    vector<int> A = {4, 0, 1, 7, 2};
    cout<<getIndex(A)<<endl;

    return 0;
}
