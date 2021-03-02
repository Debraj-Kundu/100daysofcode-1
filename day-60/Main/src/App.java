import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int val) {
        data = val;
        left = right = null;
    }
}

class Graph {
    Map<Integer, LinkedList<Integer>> adj = new HashMap<Integer, LinkedList<Integer>>();
    void add_edge(){
        
    }
}

public class App {
    /*
     * public void demo(double x) { System.out.println("D"); }
     * 
     * public void demo(float x) { System.out.println("f"); }
     */
    Node root;

    void postorder(Node root) {
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
                    root = null;
                    s.pop();
                } else {
                    root = root.right;
                }
            }
        } while (!s.isEmpty());
    }

    void printPath(int[] arr, int len) {
        for (int i = 0; i < len; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.print("\n");
    }

    void helper(Node root, int[] arr, int len) {
        if (root == null)
            return;
        arr[len] = root.data;
        len++;
        if (root.left == null && root.right == null) {
            printPath(arr, len);
        } else {
            helper(root.left, arr, len);
            helper(root.right, arr, len);
        }
    }

    void rootToLeafPath(Node root) {
        int arr[] = new int[100];
        helper(root, arr, 0);
    }

    public static void main(String[] args) throws Exception {
        /*
         * byte a = (byte) 1600;
         * 
         * int x=0, y=0; if(--x >= y++) if(--x<y) x++; else if(x<y) y++; else x--; else
         * if(x != y) y++; else --x;
         * 
         * int x = 10, y = 5; x = --y + x-- - --x + y; System.out.println(x);
         */
        // new App().demo(1);
        App tree = new App();
        tree.root = new Node(0);
        tree.root.left = new Node(1);
        tree.root.right = new Node(2);
        tree.root.left.left = new Node(3);
        tree.root.left.right = new Node(4);
        tree.root.right.left = new Node(5);
        tree.root.right.right = new Node(6);
        tree.root.left.left.right = new Node(7);
        tree.rootToLeafPath(tree.root);
    }
}
