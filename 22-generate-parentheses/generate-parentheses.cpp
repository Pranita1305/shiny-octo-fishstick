class Solution {
public:
    vector<string> result;
    void func(int n, int open, int closed,string current){
        if(current.size()==2*n) {
            result.push_back(current);
            return;
        }

        if(open<n){
            current.push_back('(');
            func(n,open+1,closed,current);
            current.pop_back();
        }

        if(closed<open){
            current.push_back(')');
            func(n,open,closed+1,current);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        func(n,0,0,"");
        return result;
    }
};