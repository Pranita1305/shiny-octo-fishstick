class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,-1);

        // for(int i=0;i<n;i++){
        //     int j=(i+1)%n;
        //     int flag=0;
        //     while(j!=i){
        //         if(nums[j]>nums[i]){
        //             res.push_back(nums[j]);
        //             flag=1;
        //             break;
        //         }
        //         j=(j+1)%n;
        //     }
        //     if(flag==0) res.push_back(-1);
        // }

        stack<int> st;

        // for(int i=0;i<n;i++){
        //     int index=(i+1)%n;
        //     st.push(nums[i]);
        //     while(!st.empty() && index!=i){
        //         st.push(nums[index]);
        //         if(st.top()>nums[i]){
        //             res[i]=nums[index];
        //             while(!st.empty()) st.pop();
        //             break;
        //         }
        //         index=(index+1)%n;
        //     }
        // }

        

        for(int i = 0; i < 2 * n; ++i) {
            int idx = i % n;
            while(!st.empty() && nums[idx] > nums[st.top()]) {
                res[st.top()] = nums[idx];
                st.pop();
            }
            if(i < n) {
                st.push(idx);
            }
        }

        return res;
    }
};

