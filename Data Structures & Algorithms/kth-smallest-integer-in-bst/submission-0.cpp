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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>st;
        int count = 0;

        TreeNode* curr = root;

        while(curr!=NULL || st.size()>0){
            while(curr!=NULL){
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            count++;

            if(count == k){
                return curr->val;
            }

          
                curr = curr->right;
            
        }

        return root->val;
    }
};
