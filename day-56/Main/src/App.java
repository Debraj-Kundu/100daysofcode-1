import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int val) {
        data = val;
    }
}

public class App {
    static void iorder(Node root) {
        if (root != null) {
            iorder(root.left);
            System.out.print(root.data + " ");
            iorder(root.right);
        }
    }

    static void lvorder(Node root) {
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);
        while (q.isEmpty() == false) {
            Node front = q.remove();
            System.out.print(front.data + " ");
            if (front.left != null)
                q.add(front.left);
            if (front.right != null)
                q.add(front.right);
        }
    }

    static void printPath(int[] arr, int n) {
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    static void dfs(Node root, int[] arr, int len) {
        if (root == null)
            return;
        arr[len] = root.data;
        len++;
        if (root.left == null && root.right == null) {
            printPath(arr, len);
            System.out.println(" ");
        } else {
            dfs(root.left, arr, len);
            dfs(root.right, arr, len);
        }
    }

    static void path(Node root) {
        int[] pathArr = new int[1000];
        dfs(root, pathArr, 0);
    }

    public static void main(String[] args) throws Exception {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        path(root);
    }
}
