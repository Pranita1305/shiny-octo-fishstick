class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> s; // stores number of occurences of each elem in any subarray
        int max_elem=-1;
        int n=nums.size();

        for(int i=0;i<n-k+1;i++){
            unordered_set<int>t;
            for(int j=i;j<i+k;j++){
                t.insert(nums[j]);
            }

            for(int num:t){
                s[num]++;
            }
        }

        for(auto[num,freq]:s){
            if(freq==1) max_elem=max(max_elem,num);
        }

        return max_elem;

    }
};