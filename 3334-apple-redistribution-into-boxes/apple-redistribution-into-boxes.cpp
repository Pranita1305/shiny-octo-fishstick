class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<int>());

        int count=0;
        int totalCap=0;

        for(int num:apple) totalCap+=num;

        int totalPref=0;
        for(int i=0;i<capacity.size();i++){
            if(totalPref>=totalCap){
                return count;
            }
            totalPref+=capacity[i];
            count++;
        }

        if(totalPref>=totalCap) return count;
        else return -1;
    }
};