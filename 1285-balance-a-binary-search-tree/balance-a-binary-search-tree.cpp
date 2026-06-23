/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& v){
        if (root == nullptr) return;
        
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }

    TreeNode* builtAVL (vector<int>& v, int l, int r){
        if (l > r) return nullptr;

        int m = l + (r - l) / 2;
        TreeNode* newNode = new TreeNode(v[m]);
        newNode->left = builtAVL(v, l, m - 1);
        newNode->right = builtAVL(v, m + 1, r);

        return newNode;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inOrder(root, v);
        root = builtAVL(v, 0, v.size()-1);

        return root;
    }
};