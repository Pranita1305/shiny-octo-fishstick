class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        unordered_set<string> hs;

        backtrack(0,nums,curr,res,hs);
        return res;
    }
private:
    void backtrack(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& res, unordered_set<string>& hs){
        string current="";
        for(int i:curr) current+=to_string(i);

        if(hs.find(current)==hs.end()){
            hs.insert(current);
            res.push_back(curr);
        }

        for(int i=index;i<nums.size();i++){
            curr.push_back(nums[i]);
            backtrack(i+1,nums,curr,res,hs);
            curr.pop_back();
        }

        return;
    }
};