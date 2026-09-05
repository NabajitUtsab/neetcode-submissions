class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        vector<string> hash = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans;
        string s;
        if (digits.empty()) {
            return ans;
        }

        dfs(0, ans, hash, digits, s);
        return ans;
    }

    void dfs(int ind, vector<string>& ans, vector<string>& hash, string digits, string s) {
        if (s.size() == digits.size()) {
            ans.push_back(s);
            return;
        }

        string cur = hash[digits[ind] - '0'];

        for (int i = 0; i < cur.size(); i++) {
            s.push_back(cur[i]);
            dfs(ind + 1, ans, hash, digits, s);
            s.pop_back();
        }
    }
};
