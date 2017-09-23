// namespace std have been included for this problem.

vector<string> letters = {
    "", "",
    "abc", "def", "ghi",
    "jkl", "mno", "pqrs",
    "tuv", "wxyz",
};

void helper(const string& digits, vector<string> &result,
            int idx, string res_so_far) {
    if (idx == digits.size()) {
        result.emplace_back(res_so_far);
        return;
    }
    for (char ch : letters[digits[idx] - '0']) {
        helper(digits, result, idx + 1, res_so_far + string(1, ch));
    }
}

vector<string> get_strings_from_nums(string digits) {
    vector<string> result;
    helper(digits, result, 0, "");
    return result;
}
