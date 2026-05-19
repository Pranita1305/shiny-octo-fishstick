class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> s;

        if(nums1.size() < nums2.size()) {
            for(int i = 0; i < nums2.size(); i++) {
                s.insert(nums2[i]);
                // if(bs(nums2, nums1[i]))
                //     return nums1[i];
            }

            for(int i=0;i<nums1.size();i++){
                if(s.find(nums1[i])!=s.end()) return nums1[i];
            }
        }
        else {
            for(int i = 0; i < nums1.size(); i++) {
                // if(bs(nums1, nums2[i]))
                //     return nums2[i];
                s.insert(nums1[i]);
            }

            for(int i=0;i<nums2.size();i++){
                if(s.find(nums2[i])!=s.end()) return nums2[i];
            }
        }



        return -1;
    }

// private:
//     bool bs(vector<int>& nums, int num) {
//         int low = 0;
//         int high = nums.size() - 1;

//         while(low <= high) {
//             int mid = low + (high - low) / 2;

//             if(nums[mid] == num)
//                 return true;
//             else if(nums[mid] > num)
//                 high = mid - 1;
//             else
//                 low = mid + 1;
//         }

//         return false;
//     }
};