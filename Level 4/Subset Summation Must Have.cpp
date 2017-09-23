// namespace std have been included for this problem.

bool helper(const vector<int> &v, int idx,
            int sum_so_far, int must, int target) {
    if (idx == (int)v.size()) {
        return sum_so_far == target;
    }
    if (v[idx] == must) {
        return helper(v, idx + 1, sum_so_far + v[idx], must, target);
    } else {
        return helper(v, idx + 1, sum_so_far, must, target) ||
               helper(v, idx + 1, sum_so_far + v[idx], must, target);
    }
}

bool group_sum_with_num(int arr[], int sz, int must_have, int target_sum) {
    vector<int> v(arr, arr + sz);
    return helper(v, 0, 0, must_have, target_sum);
}
