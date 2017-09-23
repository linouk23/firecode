// namespace std have been included for this problem.

#include <stack>
void pushLeftSubtree(treeNode* node, stack<treeNode*> &st) {
    while (node) {
        st.push(node);
        node = node->left;
    }
}

bool validate_bst_itr(treeNode* root) {
    stack<treeNode*> st;
    pushLeftSubtree(root, st);
    int prev = INT_MIN;
    while (!st.empty()) {
        auto cur = st.top();
        st.pop();
        if (cur->value <= prev) { return false; }
        prev = cur->value;
        pushLeftSubtree(cur->right, st);
    }
    return true;
}
