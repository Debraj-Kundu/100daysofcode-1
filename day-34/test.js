class Node {
  constructor(data, left, right) {
    this.data = data;
    this.left = left;
    this.right = right;
  }
  show() {
    return this.data;
  }
}


class BST {
  constructor() {
    this.root = null;
    this.inOrder = inOrder;
  }

  insertNode(root, val) {
    if (root === null) {
      let newNode = new Node(val, null, null);
      root = newNode;
    } else if (val < root.data) {
      root.left = this.insertNode(root.left, val);
    } else if (val > root.data) {
      root.right = this.insertNode(val, null, null);
    }
    return root;
  }

  insert(val) {
    this.root = this.insertNode(this.root, val);
  }
};

function inOrder(node) {
  if (node != null) {
    inOrder(node.left);
    console.log(node.show() + " ");
    inOrder(node.right);
  }
}

let nums = new BST();
nums.insert(23);
nums.insert(45);
nums.insert(16);
nums.insert(37);
nums.insert(3);
nums.insert(99);
nums.insert(22);
console.log("Inorder traversal: ");
inOrder(nums.root);
