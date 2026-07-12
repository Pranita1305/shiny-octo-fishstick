class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());

        unordered_map<int,int> m;
        

        int rank=1;
      

        for (int num : temp) {
            if (!m.count(num)) {
                m[num] = rank++;
            }
        }

        for(int &num:arr){
            num=m[num];
        }

        return arr;

    }
};