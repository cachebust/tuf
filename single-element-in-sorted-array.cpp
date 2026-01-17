#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // bruteforce
    /* int singleNonDuplicate(vector<int> &nums) {
        for (int i=0; i<nums.size()-1; i+=2) {
            if (nums[i] == nums[i+1]) {
                continue;
            } else {
                return nums[i];
            }
        }
        return -1;
    } */

    // bruteforce using XOR
    /* int singleNonDuplicate(vector<int> &nums) {
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    } */

    // binary search
    int singleNonDuplicate(vector<int> &nums) {
        int n = nums.size();
        
        // edge cases
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n-1] != nums[n-2]) return nums[n-1];

        int low = 1;
        int high = n-2;
        while(low <= high) {
            int mid = (low + high) / 2;
            
            // check if mid is the non duplicate element
            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
                return nums[mid];
            }

            // other conditions
            if ((mid % 2 == 1 && nums[mid-1] == nums[mid]) || (mid % 2 == 0 && nums[mid] == nums[mid+1])) {
                // left to mid is sorted 
                low = mid + 1;
            } else {
                high = high - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6};
    cout << s1.singleNonDuplicate(nums);
}