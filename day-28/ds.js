class Set {
  constructor() {
    this.dataStore = [];
  }
  insert(val) {
    if (this.dataStore.indexOf(val) < 0) {
      this.dataStore.push(val);
    }
  }
  remove(key) {
    let pos = this.dataStore.indexOf(key);
    if (pos > -1) {
      this.dataStore.splice(pos, 1);
    }
  }
};

class Node {
  constructor(data, left, right) {
    this.data = data;
    this.left = left;
    this.right = right;
    this.show = show;
  }
}
function show() {
  return this.data;
}
class BST {
  constructor() {
    this.root = null;
    this.inOrder = inOrder;
  }

  insert(data) {
    let n = new Node(data, null, null);
    if (this.root == null) {
      this.root = n;
    } else {
      let curr = this.root;
      let parent;
      while (true) {
        parent = curr;
        if (data < curr.data) {
          curr = curr.left;
          if (curr == null) {
            parent.left = n;
            break;
          }
        } else {
          curr = curr.right;
          if (curr == null) {
            parent.right = n;
            break;
          }
        }
      }
    }
  }
}
function inOrder(node) {
  if (node != null) {
    inOrder(node.left);
    console.log(node.show() + " ");
    inOrder(node.right);
  }
}
/* let s = new Set();
s.insert(10);s.insert(20);
s.insert(10);
console.log(s.dataStore); */

/* nums.insert(23);
nums.insert(45);
nums.insert(16);
nums.insert(37);
nums.insert(3);
nums.insert(99);
nums.insert(22);
console.log("Inorder traversal: ");
inOrder(nums.root); */

class Graph {
  constructor(v) {
    this.v = v;
    this.edge = 0;
    this.adj = [];
    for (let i = 0; i < this.v; i++) {
      this.adj[i] = [];
      this.adj[i].push(' ');
    }
  }
  addEdge(v, w) {
    this.adj[v].push(w);
    this.adj[w].push(v);
    this.edges++;
  }
  showGraph() {
    for (var i = 0; i < this.vertices; ++i) {
      console.log(i + " -> ");
      for (var j = 0; j < this.vertices; ++j) {
        if (this.adj[i][j] != undefined)
          console.log(this.adj[i][j] + ' ');
      }
      console.log();
    }
  }
};

let g = new Graph(5);
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(1,3);
g.addEdge(2,4);
g.showGraph();