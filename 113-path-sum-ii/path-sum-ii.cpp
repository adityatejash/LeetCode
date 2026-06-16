/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int targetSum, long long currSum, vector<int>& temp, vector<vector<int>>& ans) {
        if (root == nullptr) return;

        currSum += root->val;
        temp.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            if (currSum == targetSum) {
                ans.push_back(temp);
            }
        }

        solve(root->left, targetSum, currSum, temp, ans);
        solve(root->right, targetSum, currSum, temp, ans);

        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(root, targetSum, 0, temp, ans);

        return ans;
    }
};