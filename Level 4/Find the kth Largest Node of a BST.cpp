// namespace std have been included for this problem.

// Trick: int &k, think about the largest node.
treeNode* inorder(treeNode* node, int &k) {
    if (!node)      { return nullptr; }
    auto result = inorder(node->right, k);
    if (result)     { return result; }
    if (k-- == 1)   { return node; }
    result = inorder(node->left, k);
    if (result)     { return result; }
    return nullptr;
}

treeNode* find_kth_largest(treeNode* root, int k) {
    return inorder(root, k);
}


// Tricks:
// 1. k - right.size - 1 when going left,
// 2. node.size is size of a subtree where root = node,
// => root.size = left.rank + right.rank + 1
// 3. if (right.result) { return right; }
// 4. In-place size of subtree where root = node.
struct Status {
    int size;
    treeNode* result;
};

Status inorder(treeNode* node, int k) { 
    if (!node) { return { 0, nullptr }; }
    auto right = inorder(node->right, k);
    if (right.size == k - 1) { return { k, node }; }
    if (right.result)        { return right; }
    int left_k = k - right.size - 1;
    auto left = inorder(node->left, left_k);
    if (left.result)         { return left; }
    // In-place size of subtree where root = node.
    return { left.size + right.size + 1, nullptr };
}

treeNode* find_kth_largest(treeNode* root, int k) {
    return inorder(root, k).result;
}
