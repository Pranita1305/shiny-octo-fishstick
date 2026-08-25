class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int count=1;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            if(nums[i]%k==0){
                if(k*count!=nums[i]) return k*count;
                else count++;
            }
        }

        return k*count;
    }
};