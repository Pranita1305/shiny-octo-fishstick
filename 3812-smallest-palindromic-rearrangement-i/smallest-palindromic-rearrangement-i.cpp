class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size()==1) return s;

        int maxval=0;
        for(char c: s) maxval=max(maxval,(int)c);

        vector<int> freq(maxval+1,0);
        for(char c:s) freq[c]++;

        string half="";
        string mid="";

        for(int i=0;i<=maxval;i++){
            int count=freq[i];
            if(count==0) continue;

            for(int j=0;j<count/2;j++) half+=(char)i;

            if(count%2==1) mid+=(char)i;
        }
        
        string revhalf(half.rbegin(), half.rend());

        return half+mid+revhalf;

    }

};