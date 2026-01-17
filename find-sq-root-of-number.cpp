#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int floorSqrt(int n)  {
        int low = 1;
        int high = n;
        while (low <= high) {
            int mid = low + (high - low)/2;
            long long val = 1LL * mid * mid;
            // if sqrt of n is less than mid
            if (val <= (long long)n) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return high;
    }
};

int main() {
    Solution s1;
    cout << s1.floorSqrt(36);
}