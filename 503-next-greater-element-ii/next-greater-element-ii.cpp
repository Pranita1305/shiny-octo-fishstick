class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;

        for(int i=0;i<n;i++){
            int j=(i+1)%n;
            int flag=0;
            while(j!=i){
                if(nums[j]>nums[i]){
                    res.push_back(nums[j]);
                    flag=1;
                    break;
                }
                j=(j+1)%n;
            }
            if(flag==0) res.push_back(-1);
        }

        return res;
    }
};