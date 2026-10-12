class Solution {
public:
    int ma = 0;

    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        ma = max(ma, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ma;
    }
};