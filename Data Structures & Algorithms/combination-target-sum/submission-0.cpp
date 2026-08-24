class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        dfs(0, nums, temp, ans, target);
        return ans;
    }

    void dfs(int ind, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans,int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (ind >= nums.size()) {
            return;
        }

        if (nums[ind] <= target) {
            temp.push_back(nums[ind]);
            dfs(ind, nums, temp, ans, target - nums[ind]);
            temp.pop_back();
        }
        dfs(ind + 1, nums, temp, ans, target);
    }
};
