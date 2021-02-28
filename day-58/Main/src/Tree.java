import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int val) {
        data = val;
        left = right = null;
    }
}

public class Tree {
    Node root;

    Tree() {
        root = null;
    }

    void inorder() {
        Stack<Node> s = new Stack<Node>();
        while (true) {
            while (root != null) {
                s.push(root);
                root = root.left;
            }
            if (s.isEmpty())
                break;
            root = s.pop();
            System.out.print(root.data + " ");
            root = root.right;
        }
    }

    void postorder() {
        Stack<Node> s = new Stack<Node>();
        Node prev = null;
        do {
            while (root != null) {
                s.push(root);
                root = root.left;
            }
            while (root == null && !s.isEmpty()) {
                root = s.peek();
                if (root.right == null || root.right == prev) {
                    System.out.print(root.data + " ");
                    prev = root;
                    s.pop();
                    root = null;
                } else {
                    root = root.right;
                }
            }
        } while (!s.isEmpty());
    }

    public static void main(String[] args) throws Exception {
        Tree t1 = new Tree();
        t1.root = new Node(1);
        t1.root.left = new Node(2);
        t1.root.left.left = new Node(4);
        t1.root.left.right = new Node(5);
        t1.root.right = new Node(3);
        t1.root.right.left = new Node(6);
        t1.root.right.right = new Node(7);
        t1.postorder();

    }
}
