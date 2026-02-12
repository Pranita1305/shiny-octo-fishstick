class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                if (allSame(freq)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }

private:
    bool allSame(const vector<int>& freq) {
        int val = 0;

        for (int x : freq) {
            if (x > 0) {
                if (val == 0)
                    val = x;
                else if (x != val)
                    return false;
            }
        }
        return true;
    }
};
