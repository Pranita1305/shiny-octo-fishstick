/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0); // Dummy node to simplify list operations
        ListNode current = dummy;
        int carry = 0;

        // Traverse both lists until both are null
        while (l1 != null || l2 != null || carry != 0) {
            int sum = carry; // Start with the carry from the previous iteration

            // Add values from the two lists if they exist
            if (l1 != null) {
                sum += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            }

            // Create a new node for the digit at this place
            current.next = new ListNode(sum % 10); // Extract the last digit
            carry = sum / 10; // Update the carry

            // Move to the next node
            current = current.next;
        }

        // Return the resulting list (skipping the dummy node)
        return dummy.next;
    }
}