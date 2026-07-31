class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);

        for(char c:word) freq[c-'a']++;

        sort(freq.begin(),freq.end());
        int push=0;

        for(int i=25,pushCount=0;i>=0;i--){
            int ind=25-i;

            if(ind%8==0) pushCount++;

            push+=(freq[i]*pushCount);
        }

        return push;
    }
};