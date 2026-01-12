#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    // bruteforce
    /* vector<int> searchRange(vector<int> &nums, int target) {
        int low = -1;
        int high = -1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == target && low == -1) {
                low = i;
                high = i;
            } else if (nums[i] == target) {
                high = i;
            }
        }

        return {low, high};
    } */

    int binarySearchFirst(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = -1;

        while(low <= high) {
            int mid = (low + high) / 2;
            if (target <= nums[mid]) {
                if (target == nums[mid]) {
                    ans = mid;
                }
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int binarySearchSecond(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = -1;

        while(low <= high) {
            int mid = (low + high) / 2;
            if (target >= nums[mid]) {
                if (target == nums[mid]) {
                    ans = mid;
                }
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    // binary search
    vector<int> searchRange(vector<int> &nums, int target) {
        
        // first occurrence of target
        int first = binarySearchFirst(nums, target);
        int second = binarySearchSecond(nums, target);
        return {first, second};
    }
};

int main () {
    Solution s1;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> res = s1.searchRange(nums, 10);
    for (int x: res) {
        cout << x << " ";
    }
}