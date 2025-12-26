class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int prefix=0;
        
        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                prefix++;
            }
        }

        int minPenalty=prefix;
        int time=0;

        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                prefix--;
            }
            else{
                prefix++;
            }

            if(minPenalty>prefix){
                minPenalty=prefix;
                time=i+1;
            }
        }

        return time;
    }
};