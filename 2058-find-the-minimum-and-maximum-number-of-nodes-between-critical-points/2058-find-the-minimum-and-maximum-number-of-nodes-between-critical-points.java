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
    public List<Integer> localMaximaMinima(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) return new ArrayList<>();

        ListNode t1 = head;
        ListNode t2 = head.next;
        ListNode t3 = head.next.next;

        List<Integer> l = new ArrayList<>();

        int i=2;
        while (t3 != null) {
            int a = t1.val;
            int b = t2.val;
            int c = t3.val;

            if (b > a && b > c) l.add(i);

            if (b < a && b < c) l.add(i);

            t1 = t1.next;
            t2 = t2.next;
            t3 = t3.next;

            i++;
        }

        return l;
    }
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        List<Integer> l = localMaximaMinima(head);

        int n = l.size();

        if (n < 2) return new int[]{-1, -1};

        int minimum = Integer.MAX_VALUE;

        for (int i=1; i<n; i++) {
            minimum = Math.min(minimum, l.get(i) - l.get(i-1));
        }

        int maximum = l.get(n-1) - l.get(0);

        return new int[]{minimum, maximum};
    }
}