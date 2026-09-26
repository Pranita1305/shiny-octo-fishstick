class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;

        for(auto& kv:knowledge){
            mp[kv[0]]=kv[1];
        }

        string res="";

        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                string key="";
                i++;
                while(i<n && s[i]!=')'){
                    key+=s[i];
                    i++;
                }
                if(mp.count(key)) res+=mp[key];
                else res+='?';
            }
            else res+=s[i];
        }

        return res;
    }
};