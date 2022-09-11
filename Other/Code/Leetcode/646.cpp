#include "common.h"

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> arr;
        for (auto p : pairs) {
            if (arr.size() == 0 || p[0] > arr.back()) {
                arr.emplace_back(p[1]);
            } else {
                int idx = lower_bound(arr.begin(), arr.end(), p[0]) - arr.begin();
                arr[idx] = min(arr[idx], p[1]);
            }
        }
        return arr.size();
    }
};
