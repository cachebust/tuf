#include <bits/stdc++.h>

using namespace std;

class Solution {
public: 
    int findKRotation(vector<int> &nums)  {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = INT_MAX;
        int index = -1;
        while (low <= high) {
            int mid = (low + high) / 2;

            // if search space is already sorted
            if (nums[low] <= nums[high]) {
                if (nums[low] < ans) {
                    index = low;
                    ans = nums[low];
                }
                break;
            }

            // if left side of array is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] < ans) {
                    index = low;
                    ans = nums[low];
                }
                low = mid + 1;
            } else { // if right side of array is sorted
                if (nums[mid] < ans) {
                    index = mid;
                    ans = nums[mid];
                }
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {4, 5, 6, 7, -1, 1, 2, 3};
    cout << s1.findKRotation(nums);
}