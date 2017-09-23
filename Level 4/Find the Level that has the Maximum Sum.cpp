// namespace std have been included for this problem.

#include<unordered_map>
#include <queue>
#include <climits>
int find_max_sum_level(treeNode* root) {
    if (!root) { return -1; }
    queue<treeNode*> q;
    unordered_map<treeNode*, int> node2level;
    q.push(root);
    node2level[root] = 0;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        vector<treeNode*> neighbours = { cur->left, cur->right };
        for (auto neighbour : neighbours) {
            if (!neighbour) { continue; }
            node2level[neighbour] = node2level[cur] + 1;
            q.push(neighbour);
        }
    }
    unordered_map<int, int> level2sum;
    for (const auto &p : node2level) {
        int level = p.second;
        int value = p.first->value;
        level2sum[level] += value;
    }
    struct Result {
        int maxSum, level;
    } result { INT_MIN, 0 };
    for (const auto &p : level2sum) {
        if (p.second > result.maxSum) {
            result = { p.second, p.first };
        }
    }
    return result.level;
}
