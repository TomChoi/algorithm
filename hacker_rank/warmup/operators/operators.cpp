#include <bits/stdc++.h>

using namespace std;

int solve(double mc, int tp, int tx) {
    return (int)round(mc*(1 + (tp/100.f) + (tx/100.f)));
}

int main() {
    double mc;
    int tp, tx;

    cin >> mc >> tp >> tx;

    int ans = solve(mc, tp, tx);
    cout << ans<<"\n";

    return 0;
}
