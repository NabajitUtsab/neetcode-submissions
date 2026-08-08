class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;

        vector<vector<string>> ans;

        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(strs[i].begin(),strs[i].end());

            mpp[strs[i]].push_back(temp);
        }

        for(auto it:mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
