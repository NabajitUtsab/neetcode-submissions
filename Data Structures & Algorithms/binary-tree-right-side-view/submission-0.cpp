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
    vector<int> rightSideView(TreeNode* root) {
        int level = 0;
        vector<int> ans;
        insertIntoArray(root, ans, level);

        return ans;
    }
    void insertIntoArray(TreeNode* root, vector<int>& ans, int level) {
        if (root == NULL) {
            return;
        }

        if (level == ans.size()) {
            ans.push_back(root->val);
        }

        insertIntoArray(root->right, ans, level+1);
        insertIntoArray(root->left, ans, level+1);

    }
};
