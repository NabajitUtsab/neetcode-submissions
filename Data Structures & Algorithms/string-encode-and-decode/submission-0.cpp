class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        for(int i=0;i<strs.size();i++){
            ans+=to_string(strs[i].size())+"#"+strs[i];
        }

        return ans;
        
    }

    vector<string> decode(string s) {

        vector<string>result;
        int i=0;

        while(i<s.size()){
             int j=i;
            while(s[j]!='#'){
                j++;
            }
            int len=stoi(s.substr(i,j-i));

            result.push_back(s.substr(j+1,len));

            i=j+len+1;
        }

return result;
    }
};
