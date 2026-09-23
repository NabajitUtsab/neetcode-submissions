class Solution {
   public:
    string longestPalindrome(string s) {
        string newString;
        int maxCount = INT_MIN;

        for (int i = 0; i < s.size(); i++) {
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                int length = right - left + 1;
                if (length > maxCount) {
                    maxCount = length;
                    string sub = s.substr(left, length);
                    newString = sub;
                }
                left--;
                right++;
            }
        }

        for (int i = 0; i < s.size() - 1; i++) {
            int left = i, right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                int length = right - left + 1;
                if (length > maxCount) {
                    maxCount = length;
                    string sub = s.substr(left, length);
                    newString = sub;
                }
                left--;
                right++;
            }
        }

        return newString;
    }
};
