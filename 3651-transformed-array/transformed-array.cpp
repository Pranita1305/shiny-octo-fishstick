class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                res.push_back(nums[i]);
            }
            else{
                int index=(nums[i]+i)%n;
                if(index<0) index+=n;
                res.push_back(nums[index]);
            }
        }

        return res;
    }
};