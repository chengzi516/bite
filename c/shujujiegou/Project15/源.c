#define _CRT_SECURE_NO_WARNINGS 1
bool _isUnivalTree(struct TreeNode* root, int val) {
    if (root == NULL)
        return true;
    if (root->val != val)
        return false;
    return _isUnivalTree(root->left, val)
        && _isUnivalTree(root->right, val);
}

bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL)
        return true;
    int val = root->val;
    return _isUnivalTree(root, val);
}
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    size_t left = maxDepth(root->left) + 1;
    size_t right = maxDepth(root->right) + 1;
    if (right > left) {
        return right;
    }
    return left;
}
void _invertTree(struct TreeNode* root) {
    if (root) {
        struct TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        _invertTree(root->left);
        _invertTree(root->right);
    }
}

struct TreeNode* invertTree(struct TreeNode* root) {
    _invertTree(root);
    return root;
}
