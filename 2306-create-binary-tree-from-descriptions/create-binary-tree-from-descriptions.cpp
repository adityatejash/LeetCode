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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        unordered_set<int> childSet;

        for (auto& a : descriptions){
            int parent = a[0];
            int child = a[1];
            int isLeft = a[2];
        
            if (m.find(parent) == m.end()){
                m[parent] = new TreeNode(parent);
            }

            if (m.find(child) == m.end()){
                m[child] = new TreeNode(child);
            }

            isLeft == 1 ? m[parent]->left = m[child] : m[parent]->right = m[child];

            childSet.insert(child);
        }

        for (auto& a : descriptions){
            int parent = a[0];
            if (childSet.find(parent) == childSet.end()){
                return m[parent];
            }
        }

        return nullptr;
    }
};