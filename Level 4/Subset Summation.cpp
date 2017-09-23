// namespace std have been included for this problem.

bool helper(const vector<int> &v, int n, int idx, int target, int sum_so_far) {
    if (idx == n) { return (sum_so_far == target); }
    return helper(v, n, idx + 1, target, sum_so_far + v[idx]) ||
           helper(v, n, idx + 1, target, sum_so_far);
}

bool group_sum(int arr[], int size, int target) {
    vector<int> v(arr, arr + size);
    return helper(v, size, 0, target, 0);    
}
