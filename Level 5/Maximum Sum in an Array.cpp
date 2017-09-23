// namespace std have been included for this problem.
#include <climits>

int max_sum_cont_sequence(int arr[], int sz) {
    vector<int> v(arr, arr + sz);
    if (v.empty()) { return 0; }
    vector<int> dp(v.size() + 1, INT_MIN);
    // Kadane's algo: dp[idx] – max sum ends in arr[idx]
    dp[0] = v[0];
    for (int idx = 1; idx < (int)v.size(); ++idx) {
        // Either begin a new subarray or continue the previous one
        // We've got only 2 options.
        dp[idx] = v[idx] + max(0, dp[idx - 1]);
    }
    return *max_element(dp.begin(), dp.end());
}