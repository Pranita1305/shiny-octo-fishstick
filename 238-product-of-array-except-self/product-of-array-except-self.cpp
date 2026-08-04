class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> start(n,1);
        vector<int> end(n,1);

        for(int i=1;i<n;i++){
            start[i]=nums[i-1]*start[i-1];
        }

        for(int i=n-2;i>=0;i--){
            end[i]=nums[i+1]*end[i+1];
        }

        vector<int> res;
        for(int i=0;i<n;i++){
            res.push_back(start[i]*end[i]);
        }

        return res;
    }
};