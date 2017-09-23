// namespace std have been included for this problem.

struct Status {
    int num_of_found_nodes;
    treeNode* result;
};

Status postorder(treeNode* node, int a, int b) {
    if (!node) { return { 0, nullptr }; }
    auto left  = postorder(node->left, a, b);
    if (left.num_of_found_nodes == 2) { return left; }
    auto right = postorder(node->right, a, b);
    if (right.num_of_found_nodes == 2) { return right; }
    int num_of_found_nodes_in_subtree = left.num_of_found_nodes +
                                        right.num_of_found_nodes + 
                                        (node->value == a) +
                                        (node->value == b);
    if (num_of_found_nodes_in_subtree == 2) { return { 2, node }; }
    return { num_of_found_nodes_in_subtree, nullptr };
}

treeNode* find_lca(treeNode* root, int a, int b) {
    return postorder(root, a, b).result;
}
