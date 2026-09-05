class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int> max_elem(n);
        vector<int> min_elem(n);

        max_elem[0]=nums[0];
        min_elem[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            max_elem[i]=max(max_elem[i-1],nums[i]);
        }

        for(int i=n-2;i>=0;i--){
            min_elem[i]=min(min_elem[i+1],nums[i]);
        }

        for(int i=0;i<n;i++){
            if(max_elem[i]-min_elem[i]<=k) return i;
        }

        return -1;
    }
};