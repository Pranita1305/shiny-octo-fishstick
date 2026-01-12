class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string str:tokens){
            if(str=="+" || str=="-" || str=="/" || str=="*"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();

                if(str=="+" ) st.push(second+first);
                else if(str=="-" ) st.push(second-first);
                else if(str=="*" ) st.push(second*first);
                else st.push(second/first);
            }
            else{
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};