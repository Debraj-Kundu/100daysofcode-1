import java.util.Queue;

class Node {
    int data;
    Node left, right;

    Node(int val) {
        this.data = val;
        this.left = this.right = null;
    }
}

public class App {
    static Node root;

    App(int key) {
        root = new Node(key);
    }

    App() {
        root = null;
    }

    void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            inorder(root.right);
            System.out.print(root.data + " ");
        }
    }

    public static void main(String[] args) throws Exception {
        App tree = new App();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.inorder(root);
    }
}
