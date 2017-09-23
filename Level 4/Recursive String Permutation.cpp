// namespace std have been included for this problem.

void helper(const string &s, vector<bool> &used,
            string perm_so_far, vector<string> &result) {
    if (perm_so_far.length() == s.length()) {
        result.emplace_back(perm_so_far);
        return;
    }
    for (int idx = 0; idx < s.length(); ++idx) {
        if (used[idx]) { continue; }
        used[idx] = true;
        helper(s, used, perm_so_far + s[idx], result);
        used[idx] = false;
    }
}

vector<string> get_permutations(string s) {
    vector<string> result;
    if (s.empty()) { return result; }
    vector<bool> used(s.length(), false);
    helper(s, used, "", result);
    return result;
}
