#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // linear search
    /*
    int search(vector<int> &nums, int k) {
       for (int i=0; i<nums.size(); i++) {
            if (nums[i] == k) {
                return i;
            }
       }
       return -1;
    }
    */

    // binary search
    int search(vector<int> &nums, int k) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == k) return mid;

            // check if first half is sorted
            if (nums[low] <= nums[mid]) {
                // check if target is present in first half
                if (nums[low] <= k && k <= nums[mid]) {
                    high = mid - 1;
                } else {
                    // target not present in first half
                    low = mid + 1;
                }
            } else {
                // check if second half is sorted
                // check if target is present in second half
                if (nums[mid] <= k && k <= nums[high]) {
                    low = mid + 1;
                } else {
                    // target not present in second half
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};


int main() {
    Solution s1;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << s1.search(nums, 2);
}