class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int result_max=solve(nums,k);
        int result_atmost=solve(nums,k-1);

        return result_max-result_atmost;
    }

    int solve(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,odd=0;

        int count=0;

        for(int j=0;j<n;j++){
            if(nums[j]%2!=0) odd++;

            while(odd>k){
                if(nums[i]%2!=0) odd--;
                i++;
            }

            count+=j-i+1;
        }

        return count;
    }
};