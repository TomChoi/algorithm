#include <iostream>

using namespace std;

vector<string> function(const int row, const int col, vector<string> grid, int count) {
    
    
    for(int r=0; r < row; ++r) {
        for(int c=0; c < col; ++c) {
            
            

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int row, col;
    cin>>row>>col;

    vector<string> grid(row);

    for(int i=0; i<row; ++i) {
        cin>>grid[i];
    }
    
    int count = 0;
    vector<string> outGrid = function(row, col, grid, &count);

    cout<<count<<"\n";
    
    for(string &s: outGrid) 
        cout<<s<<"\n";

    return 0;
}
