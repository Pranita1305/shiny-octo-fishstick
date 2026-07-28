class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();

        int l=0;
        int r=0;
        int maxLength=0;
        unordered_map<char,int>set;

        while(r<n){
            
            if(set.count(s[r]) && set[s[r]] >= l){
                l = set[s[r]] + 1;
            }
            set[s[r]] = r;
            maxLength = max(maxLength, r - l + 1);
            
            r++;
        }

        return maxLength;
    }
};