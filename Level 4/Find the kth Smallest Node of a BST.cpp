// namespace std have been included for this problem.

// treeNode* inorder(treeNode* node, int &k) {
//     if (!node) { return nullptr; }
//     auto left = inorder(node->left, k);
//     if (left) { return left; }
//     if (k-- == 1) { return node; }
//     auto right = inorder(node->right, k);
//     if (right) { return right; }
//     return nullptr;
// }

// treeNode* find_kth_smallest(treeNode* root, int k) {
//     return inorder(root, k);
// }

struct Status {
    int size;
    treeNode* result;
};

Status inorder(treeNode* node, int k) {
    if (node == nullptr) { return { 0, nullptr }; }
    auto left_subtree = inorder(node->left, k);
    if (left_subtree.result) { return left_subtree; }
    if (left_subtree.size == k - 1) { return { k, node }; }
    auto right_subtree = inorder(node->right, k - left_subtree.size - 1);
    if (right_subtree.result) { return right_subtree; }
    int size = left_subtree.size + 1 + right_subtree.size;
    return { size, nullptr };
}

treeNode* find_kth_smallest(treeNode* root, int k) {
    return inorder(root, k).result;
}
