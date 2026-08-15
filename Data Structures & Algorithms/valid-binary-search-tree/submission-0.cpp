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
    bool isValidBST(TreeNode* root) {
        bool check = checkTheTree(LLONG_MIN, root, LLONG_MAX);

        if (check == false) {
            return false;
        }
        return true;
    }

    bool checkTheTree(long long mini, TreeNode* node, long long maxi) {
        if (node == NULL) {
            return true;
        }

        if (!(mini < node->val && node->val < maxi)) {
            return false;
        }

        return checkTheTree(mini, node->left, node->val) &&
               checkTheTree(node->val, node->right, maxi);
    }
};
