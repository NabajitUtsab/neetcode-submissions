/*call a recursive function where its track openBracket count and closeBracket count.

if openBracket< n then push (
if openBracket > closeBracket then push )*/


class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";

        dfs(0, 0, n, ans, s);
        return ans;
    }

    void dfs(int open, int close, int n, vector<string>& ans, string s) {
        if (open == n && close == n) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            dfs(open + 1, close, n, ans, s + '(');
        }
        if (open > close) {
            dfs(open, close + 1, n, ans, s + ')');
        }
    }
};
