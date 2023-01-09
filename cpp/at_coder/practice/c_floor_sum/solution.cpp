#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int queries;
    cin>>queries;

    for(int q = 0; q < queries; ++q) { 
        long long n,m,a,b;
        cin>>n>>m>>a>>b;

        long long sum = 0;
        for(long long i = 0; i < n; ++i) {
            sum += floor((a * i + b) / m);
        }
        cout<<sum<<"\n";
    }

    return 0;
}
