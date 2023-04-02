#define _CRT_SECURE_NO_WARNINGS 1
bool issametree(struct TreeNode* tr1, struct TreeNode* tr2) {
    if (tr1 == NULL && tr2 == NULL)
        return true;
    else if (tr1 == NULL || tr2 == NULL)
        return false;
    else if (tr1->val != tr2->val)
        return false;
    else
        return issametree(tr1->left, tr2->left) && issametree(tr1->right, tr2->right);
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL)
        return false;

    if (issametree(root, subRoot))
        return true;
    else if (root->left == NULL && root->right == NULL)
        return false;
    else
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}