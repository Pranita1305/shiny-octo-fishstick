class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int n=s.size();
        int max_length=0;

        int i=0,j=0;

        while(i<=j && j<n){
            freq[s[j]]++;

            while(freq[s[j]]>1){
                freq[s[i]]--;
                i++;
            }

            max_length=max(max_length,j-i+1);
            j++;
        }

        return max_length;
    }
};