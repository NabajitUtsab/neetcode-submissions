class Solution {
   public:
    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;

        if (nums.size() == 1) {
            return nums[0];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0) {
                temp1.push_back(nums[i]);
            }
            if (i < nums.size() - 1) {
                temp2.push_back(nums[i]);
            }
        }

        int withoutFirst = dfs(temp1);
        int withoutLast = dfs(temp2);

        return max(withoutFirst, withoutLast);
    }

    int dfs(vector<int>& temp) {
        int outPrev = 0;
        int prev = temp[0];
        for (int i = 1; i < temp.size(); i++) {
            int pick = temp[i] + outPrev;
            int notPick = 0 + prev;

            int cur = max(pick, notPick);
            outPrev = prev;
            prev = cur;
        }

        return prev;
    }
};
