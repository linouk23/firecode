// namespace std have been included for this problem.

bool helper(const vector<int> &v, int idx,
            int sum_so_far, int target) {
    if (idx == (int)v.size()) {
        return sum_so_far == target;
    }
    return helper(v, idx + 1, sum_so_far + v[idx], target) ||
           helper(v, idx + 1, sum_so_far, target);
}

bool split_array(int arr[], int sz) {
    vector<int> v(arr, arr + sz);
    if (v.empty()) { return false; }
    int sum = accumulate(v.begin(), v.end(), 0);
    if (sum % 2) { return false; }
    return helper(v, 0, 0, sum / 2);
}