import java.util.*;

class stackfromqueue {

    static class Stack {
        static Queue<Integer> queue1 = new LinkedList<Integer>();
        static Queue<Integer> queue2 = new LinkedList<Integer>();

        static void push(int element) {
            queue2.add(element);

            while (!queue1.isEmpty()) {
                queue2.add(queue1.peek());
                queue1.remove();
            }

            Queue<Integer> temp = queue1;
            queue1 = queue2;
            queue2 = temp;
        }

        static void pop() {
            if (!queue1.isEmpty()) {
                queue1.remove();
            }
        }

        static int top() {
            if (queue1.isEmpty()) {
                return -1;
            }
            return queue1.peek();
        }

        static int size() {
            return queue1.size();
        }
    }

    public static void main(String[] args) {
        Stack stack = new Stack();
        stack.push(1);
        stack.push(2);
        stack.push(3);

        System.out.println("Current size: " + stack.size());
        System.out.println(stack.top());
        stack.pop();
        System.out.println(stack.top());
        stack.pop();
        System.out.println(stack.top());

        System.out.println("Current size: " + stack.size());
    }
}
