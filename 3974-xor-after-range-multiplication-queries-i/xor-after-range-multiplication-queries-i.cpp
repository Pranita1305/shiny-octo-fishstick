class Solution {
const int MOD = 1e9 + 7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        int m=nums.size();

        for(int i=0;i<n;i++){
            int index=queries[i][0];
            int right=queries[i][1];
            int k=queries[i][2];
            int val=queries[i][3];

            while(index<=right && index<m){
                nums[index] = (int)(((long long)nums[index] * val) % MOD);
                index+=k;
            }
        }

        int ans=nums[0];
        for(int i=1;i<m;i++){
            ans=ans^nums[i];
        }

        return ans;
    }
};