#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int numsSize, int k){
    int rot = k % numsSize;
    int rotIdx = numsSize - rot;
    if(rot == 0) return;

    for(int i=0; i<numsSize; ++i) {
        while(i < r) {
            int tmep = nums[i];
            nums[i] = nums[r];
            nums[r] = temp;
            i++; r++;
            if(
        }
    }

}

int main() {
    int n, k;
    cin>>n>>k;
    
    vector<int> nums(n);
    for(int i=0; i<n; ++i) {
        nums[i] = i+1;
    }

    rotate(nums, n, k);

    for(int i=0; i<n; ++i) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    return 0;
}
