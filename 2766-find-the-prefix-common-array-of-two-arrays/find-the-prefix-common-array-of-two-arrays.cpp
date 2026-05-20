class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> s;
        int count=0;

        vector<int> res;

        for(int i=0;i<A.size();i++){

            if(A[i]==B[i]) res.push_back(++count);

            else{
                if(s.find(A[i])!=s.end()) count++;
                if(s.find(B[i])!=s.end()) count++;
                res.push_back(count);
            }

            if(s.find(A[i])==s.end()) s.insert(A[i]);
            if(s.find(B[i])==s.end()) s.insert(B[i]);
        }

        return res;
    }
};