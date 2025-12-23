class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
       
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a[0] < b[0];
        });

        int n = events.size();

        
        vector<int> starts(n);
        for (int i = 0; i < n; i++) {
            starts[i] = events[i][0];
        }

        
        vector<int> suffixMax(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }

        int ans = 0;

        
        for (int i = 0; i < n; i++) {
            int start = events[i][0];
            int end = events[i][1];
            int value = events[i][2];

            
            ans = max(ans, value);

            
            int idx = lower_bound(starts.begin(), starts.end(), end + 1) - starts.begin();

            if (idx < n) {
                ans = max(ans, value + suffixMax[idx]);
            }
        }

        return ans;
    }
};
