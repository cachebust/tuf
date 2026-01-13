#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    // linear
    /*
    bool searchInARotatedSortedArrayII(vector<int> &nums, int k)  {
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == k) {
                return true;
            }
        }
        return false;
    } */

    bool searchInARotatedSortedArrayII(vector<int> &nums, int k)  {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == k) return true;

            // handle duplicates
            if (nums[mid] == nums[low] && nums[mid] == nums[high]) {
                low += 1;
                high -= 1;
                continue;
            }

            if (nums[low] <= nums[mid]) {
                if (nums[low] <= k && k <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] <= k && k <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {3, 1, 2, 3, 3, 3, 3};
    cout << s1.searchInARotatedSortedArrayII(nums, 1);
}