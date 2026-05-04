//783. Minimum Distance Between BST Nodes

//https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

class Solution {
public:
    vector<int>inorder;

    void inOrderTraversal(TreeNode* root){
        if(root == NULL) return;
        inOrderTraversal(root->left);
        inorder.push_back(root->val);
        inOrderTraversal(root->right);

    }
    int minDiffInBST(TreeNode* root) {
        inOrderTraversal(root); 
        int ans = INT_MAX;
        for(int i=1; i<inorder.size(); i++){
            ans = min(ans, inorder[i]-inorder[i-1]);
        }
        return ans;
    }
};