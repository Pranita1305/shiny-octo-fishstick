class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        int max_length=0;

        for(char ch:s){
            mp[ch]=0;
        }

        int i=0,j=0;
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]]>2){
                mp[s[i]]--;
                i++;
            }

            max_length=max(max_length,j-i+1);
            j++;
        }

        return max_length;
    }
};