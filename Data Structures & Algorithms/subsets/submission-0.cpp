class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(0, nums, temp, ans);
        return ans;
    }


    void dfs(int ind, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        if (ind >= nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        dfs(ind + 1, nums, temp, ans);
        temp.pop_back();
        dfs(ind + 1, nums, temp, ans);
    }
};
