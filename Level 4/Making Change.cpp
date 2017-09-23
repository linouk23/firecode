// namespace std have been included for this problem.

int make_change(int coins_[], int n, int amount) {
    if (amount < 0) { return 0; }
    vector<int> coins(coins_, coins_ + n);
    // reverse(coins.begin(), coins.end());
    vector<vector<int>> dp(n + 2, vector<int> (amount + 1, 0));
    // 121, 112, 211 should count as one
    // -> 112
    // Base cases:
    dp[0][0] = 1; // like it's string instead of
    // for (int k = 1; k <= n; ++k) { dp[k][0] = 1; }
    
    // O(N^2)
    // Let dp[k][sum] be the number of possible ways
    // of representing a sum using first k coins.
    for (int sum = 0; sum <= amount; ++sum) {
        for (int k = 1; k <= n; ++k) {
            int idx_k = k - 1;
            int coin = coins[idx_k];
            int cost_use = (sum - coin >= 0) ? dp[k][sum - coin] : 0;
            dp[k][sum] = cost_use +      // use coin_k
                         dp[k - 1][sum]; // don't use coin_k                          
        }
    }
    return dp[n][amount];
}
