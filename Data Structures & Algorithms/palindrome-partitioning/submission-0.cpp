class Solution {
   public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        dfs(0, ans, temp, s);
        return ans;
    }

    void dfs(int ind, vector<vector<string>>& ans, vector<string>& temp, string s) {
        if (ind == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = ind; i < s.size(); i++) {
            if (isPalindrome(ind, i, s) == true) {
                string cur = s.substr(ind, i - ind + 1);
                temp.push_back(cur);
                dfs(i + 1, ans, temp, s);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(int i, int j, string s) {
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
