#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    // bruteforce
    /*
    int findMin(vector<int> &arr)  {
        int ans = INT_MAX;
        for (int i=1; i<arr.size(); i++) {
            ans = min(ans, arr[i]);
        }
        return ans;
    }
    */

    // binary search
    int findMin(vector<int> &arr) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;
            // check if left side is sorted
            if (arr[low] <= arr[mid]) {
                ans = min(ans, arr[low]); 
                low = mid + 1;
            } else {
                ans = min(ans, arr[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s1;
    vector<int> arr = {3, 4, 5, 1, 2};
    cout << s1.findMin(arr);
}