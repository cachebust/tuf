#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    // return 1 if == m
    // return 2 if > m
    // return 0 if < m
    int func(int mid, int n, int m) {
        long long ans = 1;
        for (int i=1; i<=n; i++) {
            ans = ans * mid;
            if (ans > m) {
                return 2;
            }
        }
        if (ans == m) return 1;
        return 0;
    }

public:
    int NthRoot(int N, int M) {
        // linear search

        /* long long ans = -1;
        for (int i=0; i<M; i++) {
            ans = Pow(i, N);
            if (ans == M * 1LL) {
                return i;
            } else if (ans > M * 1LL) {
                return -1;
            }
        }
        return -1;
    } */

    // binary search
        long long ans = -1;
        int low = 1;
        int high = M;
        while (low <= high) {
            int mid = (low + high) / 2;
            int midN = func(mid, N, M);
            if (midN == 1) {
                return mid;
            } else if (midN == 0) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
        return -1; 
    }
};


int main() {
    Solution s1;
    cout << s1.NthRoot(3, 27);
}