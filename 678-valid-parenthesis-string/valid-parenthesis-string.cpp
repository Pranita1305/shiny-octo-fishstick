class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int i=0;
        int j=0;

        for(char ch:s){
            if(ch=='('){
                i++;
                j++;
            }
            else if(ch==')'){
                if(i>0)i--;
                j--;
            }
            else{
                if(i>0)i--;
                j++;
            }

            if(j<0) return false;
        }

        return (i==0);
    }
};