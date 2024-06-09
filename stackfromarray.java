import java.io.*;
import java.util.*;

class GenericStack<T> {

    ArrayList<T> stackArray;
    int top = -1;
    int maxSize;

    GenericStack(int maxSize) {
        this.maxSize = maxSize;
        this.stackArray = new ArrayList<T>(maxSize);
    }

    void push(T element) {
        if (top + 1 == maxSize) {
            System.out.println("Stack Overflow");
        } else {
            top = top + 1;
            if (stackArray.size() > top) {
                stackArray.set(top, element);
            } else {
                stackArray.add(element);
            }
        }
    }

    T peek() {
        if (top == -1) {
            System.out.println("Stack Underflow");
            return null;
        } else {
            return stackArray.get(top);
        }
    }

    void pop() {
        if (top == -1) {
            System.out.println("Stack Underflow");
        } else {
            top--;
        }
    }

    boolean isEmpty() {
        return top == -1;
    }

    @Override
    public String toString() {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < top; i++) {
            result.append(stackArray.get(i)).append("->");
        }
        result.append(stackArray.get(top));
        return result.toString();
    }
}

public class stackfromarray {

    public static void main(String[] args) {
        GenericStack<Integer> intStack = new GenericStack<>(3);
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);
        System.out.println("intStack after pushing 10, 20 and 30 :\n" + intStack);
        intStack.pop();
        System.out.println("intStack after pop :\n" + intStack);

        GenericStack<String> stringStack = new GenericStack<>(3);
        stringStack.push("hello");
        stringStack.push("world");
        stringStack.push("java");
        System.out.println("\nstringStack after pushing 3 elements :\n" + stringStack);
        System.out.println("stringStack after pushing 4th element :");
        stringStack.push("okay done");

        GenericStack<Float> floatStack = new GenericStack<>(2);
        floatStack.push(100.0f);
        floatStack.push(200.0f);
        System.out.println("\nfloatStack after pushing 2 elements :\n" + floatStack);
        System.out.println("top element of floatStack:\n" + floatStack.peek());
    }
}
