class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();

        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(happiness[i]);
        }

        int turns=0;
        long long happy=0;
        while(!pq.empty() && k>0){
            int h=pq.top();
            if(h-turns>0){
                happy+=(h-turns);
            }
            else{
                break;
            }
            pq.pop();
            turns++;
            k--;
        }

        return happy;
    }
};