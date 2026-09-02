class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool odd = false;
        bool even = false;

        int i = 0, j = i + 1;

        while (j < nums1.size()) {

            if (nums1[i] % 2 == 0)
                even = true;
            else
                odd = true;

            if (nums1[j] % 2 == 0)
                even = true;
            else
                odd = true;

            i++;
            j++;

            if (even && odd)
                return true;
        }

        return true;
    }
};