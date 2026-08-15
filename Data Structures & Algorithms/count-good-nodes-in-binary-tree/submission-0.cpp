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
    int goodNodes(TreeNode* root) {
        int good = 0;
        int maximum = root->val;

        counting(root,maximum,good);
        return good;
    }

    void counting(TreeNode* node,int maximum,int &good){
        if(node == NULL){
            return ;
        }

        if(node->val >= maximum){
            good++;
            maximum = node->val;
        }

        counting(node->left,maximum,good);
        counting(node->right,maximum,good);
        
    }
};
