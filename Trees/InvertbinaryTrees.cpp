//226. Invert Binary Tree
//https://leetcode.com/problems/invert-binary-tree/description/


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(root == NULL)
        return 0;

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->right);
        invertTree(root->left);

        return root;
    }
};