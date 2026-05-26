class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        int count=0;

        vector<char> upper(26,-1), lower(26,-1);

        for(char c:word){
            if(islower(c)) lower[c-'a']=1;
            if(isupper(c)) upper[c-'A']=1;
        }

        for(int i=0;i<26;i++){
            if(lower[i]!=-1 && upper[i]!=-1) count++;
        }

        return count;
    }
};