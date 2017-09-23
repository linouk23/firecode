// namespace std have been included for this problem.

vector<vector<int>> generate_pascal_triangle(int num_rows) {
    vector<vector<int>> result(num_rows);
    for (int row = 1; row <= num_rows; ++row) {
        result[row - 1].resize(row, 1);
        for (int col = 2; col < row; ++col) {
            result[row - 1][col - 1] = result[row - 1][col - 2] +
                                       result[row - 2][col - 2];
        }
    }
    return result;
}
