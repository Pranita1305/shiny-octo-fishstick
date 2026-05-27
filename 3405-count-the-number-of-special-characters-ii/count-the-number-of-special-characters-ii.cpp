class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        vector<int> lastLower(26, -1), lastUpper(26, -1);
        int n = word.size();

        for (int i = 0; i < n; ++i) {
            char c = word[i];
            if (islower(c)) lastLower[c - 'a'] = i;
            if (isupper(c)){
                if(lastUpper[c - 'A']!=-1) continue;
                lastUpper[c - 'A'] = i;
            }
        }

        int count = 0;
        for (int i = 0; i < 26; ++i) {
            
            if (lastLower[i] != -1 && lastUpper[i] != -1 && lastUpper[i] > lastLower[i]) {
                count++;
            }
        }
        return count;
    }
};