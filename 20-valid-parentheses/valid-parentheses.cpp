class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char x:s){
            if(st.empty()){
                st.push(x);
            }
            else{
                char prev=st.top();
                if(prev=='(' && x==')') st.pop();
                else if(prev=='{' && x=='}') st.pop();
                else if(prev=='[' && x==']') st.pop();
                else st.push(x);
            }
        }

        if(st.empty()) return true;

        return false;
    }
};