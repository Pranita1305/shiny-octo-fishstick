class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        int pos = 1;
        int firstCP = -1;
        int prevCP = -1;

        int minDist = INT_MAX;
        int maxDist = -1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != nullptr && curr->next != nullptr) {

            bool critical =
                (curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val);

            if (critical) {

                if (firstCP == -1) {
                    firstCP = pos;
                }

                if (prevCP != -1) {
                    minDist = min(minDist, pos - prevCP);
                    maxDist = max(maxDist, pos - firstCP);
                }

                prevCP = pos;
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        if (minDist == INT_MAX) {
            return {-1, -1};
        }

        return {minDist, maxDist};
    }
};