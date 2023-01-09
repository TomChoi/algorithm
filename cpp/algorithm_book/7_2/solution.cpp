#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(string::iterator& it) {
    char head = *it;
    it++;
    if(head == 'w' || head == 'b') {
        return string(1, head);
    }

    string upperLeft = solution(it);
    string upperRight = solution(it);
    string lowerLeft = solution(it);
    string lowerRight = solution(it);

    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    while(n--) {
        string tree;
        cin>>tree;
        string::iterator it = tree.begin();        
        cout<<solution(it)<<"\n";
    }

    return 0;
}
