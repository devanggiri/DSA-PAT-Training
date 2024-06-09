import java.io.*;

class ListNode {
    int value;
    ListNode next;

    ListNode(int val) {
        value = val;
        next = null;
    }
}

class mergeksortedlinkedlist {

    static ListNode head;
    static ListNode temp;

    static void printList(ListNode node) {
        while (node != null) {
            System.out.print(node.value + " ");
            node = node.next;
        }
        System.out.println();
    }

    static ListNode mergeKLists(ListNode lists[], int last) {
        for (int i = 1; i <= last; i++) {
            while (true) {
                ListNode head0 = lists[0];
                ListNode headI = lists[i];

                if (headI == null)
                    break;

                if (head0.value >= headI.value) {
                    lists[i] = headI.next;
                    headI.next = head0;
                    lists[0] = headI;
                } else {
                    while (head0.next != null) {
                        if (head0.next.value >= headI.value) {
                            lists[i] = headI.next;
                            headI.next = head0.next;
                            head0.next = headI;
                            break;
                        }

                        head0 = head0.next;

                        if (head0.next == null) {
                            lists[i] = headI.next;
                            headI.next = null;
                            head0.next = headI;
                            head0.next.next = null;
                            break;
                        }
                    }
                }
            }
        }
        return lists[0];
    }

    public static void main(String[] args) {
        int k = 3;
        int n = 4;

        ListNode[] lists = new ListNode[k];

        lists[0] = new ListNode(1);
        lists[0].next = new ListNode(3);
        lists[0].next.next = new ListNode(5);
        lists[0].next.next.next = new ListNode(7);

        lists[1] = new ListNode(2);
        lists[1].next = new ListNode(4);
        lists[1].next.next = new ListNode(6);
        lists[1].next.next.next = new ListNode(8);

        lists[2] = new ListNode(0);
        lists[2].next = new ListNode(9);
        lists[2].next.next = new ListNode(10);
        lists[2].next.next.next = new ListNode(11);

        head = mergeKLists(lists, k - 1);
        printList(head);
    }
}
