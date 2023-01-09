#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;

    cout<<s.substr(0,s.find('.'))<<endl;

    return 0;
}
