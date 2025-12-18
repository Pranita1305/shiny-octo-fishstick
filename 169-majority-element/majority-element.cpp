class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();

        int count=0;
        int majority;

        for(int i=0;i<n;i++){
            if(count) count+=(nums[i]==majority?1:-1);
            else{
                majority=nums[i];
                count=1;
            }
        }

        return majority;
    }
};