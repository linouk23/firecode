// namespace std have been included for this problem.

bool hasOverlap(const Interval &in1, const Interval &in2) {
    return in1.start <= in2.end && in2.start <= in1.end;
}

vector<Interval> insert_range(vector<Interval> intervals_list, Interval insert) {
    if (intervals_list.empty()) { return { insert }; }
    vector<Interval> result;
    int idx = 0, n = (int)intervals_list.size();
    while (idx < n && intervals_list[idx].end < insert.start) {
        result.emplace_back(intervals_list[idx]);
        ++idx;
    }
    while (idx < n && hasOverlap(insert, intervals_list[idx])) {
        insert.start = min(insert.start, intervals_list[idx].start);
        insert.end = max(insert.end, intervals_list[idx].end);
        ++idx;
    }
    result.emplace_back(insert);
    while (idx < n) {
        result.emplace_back(intervals_list[idx]);
        ++idx;
    }
    return result;
}
