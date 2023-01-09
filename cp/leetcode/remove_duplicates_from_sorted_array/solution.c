#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int ans = numSize;
    for(int i=1; i<numSize; ++i) {
        int j = i;
        while(j>0 && nums[j-1] >= nums[j]) {
            if(nums[j])
            swap(nums[j-1], nums[j]);
            j--;
        }
    }
    return ans;
}
   
int main() {
    
