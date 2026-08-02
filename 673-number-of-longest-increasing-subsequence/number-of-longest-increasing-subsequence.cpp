class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<int> length(n,1);
        vector<int> count(n,1);

        int max_length=INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(length[i]<length[j]+1){
                        length[i]=length[j]+1;
                        count[i]=count[j];
                    }
                    else if(length[i]==length[j]+1){
                        count[i]+=count[j];
                    }
                }
            }

            max_length=max(max_length,length[i]);
        }

        int res=0;
        for(int i=0;i<n;i++){
            if(length[i]==max_length) res+=count[i];
        }

        return res;
    }
};