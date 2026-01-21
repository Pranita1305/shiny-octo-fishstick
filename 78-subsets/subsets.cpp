class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        
        powerSet(0,nums,current,result);

        return result;
    }
private:
    void powerSet(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result){
        if(index==nums.size()){
            result.push_back(current);
            return ;
        }

        powerSet(index+1,nums,current,result);

        current.push_back(nums[index]);
        powerSet(index+1,nums,current,result);

        current.pop_back();

        return;
    }
};