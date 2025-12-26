class Solution {
public:
    string reverseVowels(string s) {
        int n=s.size();
        int l=0;
        int r=n-1;

        set<char> vowels={'a','e','i','o','u','A','E','I','O','U'};

        while(l<r){
            if(vowels.find(s[l])!=vowels.end() && vowels.find(s[r])!=vowels.end()){
                swap(s[l],s[r]);
                l++;
                r--;
            }
            else if(vowels.find(s[l])!=vowels.end()){
                r--;
            }
            else{
                l++;
            }
        }

        return s;
    }
};