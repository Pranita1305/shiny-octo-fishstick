class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int half = k / 2;

        // 1. Base profit without any modification
        long long baseProfit = 0;
        for (int i = 0; i < n; i++) {
            baseProfit += 1LL * strategy[i] * prices[i];
        }

        // 2. Initial window [0 ... k-1]
        long long windowProfit = 0;   // current profit in window
        long long forcedSellProfit = 0; // profit if last half forced to sell

        for (int i = 0; i < k; i++) {
            windowProfit += 1LL * strategy[i] * prices[i];
            if (i >= half) {
                forcedSellProfit += prices[i];
            }
        }

        long long bestGain = max(0LL, forcedSellProfit - windowProfit);

        // 3. Slide the window
        for (int r = k; r < n; r++) {
            int l = r - k + 1;

            // Update window profit
            windowProfit += 1LL * strategy[r] * prices[r];
            windowProfit -= 1LL * strategy[l - 1] * prices[l - 1];

            // Update forced sell profit (last k/2 elements)
            forcedSellProfit += prices[r];
            forcedSellProfit -= prices[l - 1 + half];

            bestGain = max(bestGain, forcedSellProfit - windowProfit);
        }

        return baseProfit + bestGain;
    }
};
