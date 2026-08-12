class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq;
        int max_length=INT_MIN;

        int i=0;

        for(int j=0;j<n;j++){

            freq[nums[j]]++;
            
            while(freq[nums[j]]>k){
                freq[nums[i]]--;
                i++;
            }
            

            max_length=max(max_length,j-i+1); 
        }

        return max_length;
    }
};