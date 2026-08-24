class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, temp, ans, target);

        return ans;
    }

    void dfs(int ind, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans,
             int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (ind >= candidates.size()) {
            return;
        }

        if (target >= candidates[ind]) {
            temp.push_back(candidates[ind]);
            dfs(ind + 1, candidates, temp, ans, target - candidates[ind]);
            temp.pop_back();
        }

        while (ind + 1 < candidates.size() && candidates[ind] == candidates[ind + 1]) {
            ind++;
        }
        dfs(ind + 1, candidates, temp, ans, target);
    }
};
