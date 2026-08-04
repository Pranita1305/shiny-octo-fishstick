class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_prof=0;
        int min_price=INT_MAX;

        for(int i:prices){
            if(i<min_price){
                min_price=i;
            }

            max_prof=max(max_prof,i-min_price);
        }

        return max_prof;
    }
};