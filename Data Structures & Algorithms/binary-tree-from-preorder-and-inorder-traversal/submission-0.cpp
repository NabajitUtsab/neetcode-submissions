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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return NULL;
        }

        TreeNode* root = new TreeNode (preorder[0]);
        int mid = findTheMid(preorder[0], inorder);

        vector<int> leftPreOrder(preorder.begin() + 1, preorder.begin() + (mid + 1));
        vector<int> rightPreOrder(preorder.begin() + (mid + 1), preorder.end());

        vector<int> leftInOrder(inorder.begin(), inorder.begin() + mid);
        vector<int> rightInOrder(inorder.begin() + (mid + 1), inorder.end());

        root->left = buildTree(leftPreOrder, leftInOrder);
        root->right = buildTree(rightPreOrder, rightInOrder);

        return root;
    }

    int findTheMid(int target, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            if (target == inorder[i]) {
                return i;
            }
        }

        return 0;
    }
};
