class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int p=0;
        int q=0;


        while(p+1<n && nums[p+1]>nums[p]){
            p++;
        }

        if(p==0 || p==n-1) return false;
        q=p;

        while(q+1<n && nums[q+1]<nums[q]){
            q++;
        }

        if(q==n-1 || q==p) return false;

        int j=q;

        while(j+1<n && nums[j+1]>nums[j]){
            j++;
        }

        if(j==n-1) return true;

        return false;
    }
};