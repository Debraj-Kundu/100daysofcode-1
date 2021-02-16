/* const btn = document.querySelector('button');

btn.addEventListener('click', () => {
  requestAnimationFrame(() => {
    console.log('animation queue 1');
  });
  Promise.resolve().then(() => console.log('Microtask 1'));
  console.log('Listner 1');
});
btn.addEventListener('click', () => {
  requestAnimationFrame(() => {
    console.log('animation queue 2');
  });
  Promise.resolve().then(() => console.log('Microtask 2'));
  console.log('Listner 2');
}); */
/* btn.click(); */

class Node {
  constructor(val = 0, left = null, right = null) {
    this.data = val;
    this.left = left;
    this.right = right;
  }
};

function preorder(root) {
  const stack = [];
  while (true) {
    while (root !== null) {

      stack.push(root);
      root = root.left;
    }
    if (stack.length === 0) {
      return;
    }
    root = stack.pop();
    console.log(root.data, ' ');
    root = root.right;
  }
}

function postorder(root) {
  const stack = [];
  let prev = null;
  do {
    while (root !== null) {
      stack.push(root);
      root = root.left;
    }
    while (root === null && stack.length !== 0) {
      root = stack[stack.length - 1];
      if (root.right === null || root.right === prev) {
        console.log(root.data);
        prev = stack.pop();
        root = null;
      } else {
        root = root.right;
      }
    }
  } while (stack.length !== 0);
}

function lvorder(root) {
  const queue = [];
  queue.push(root);
  while (queue.length !== 0) {
    root = queue.shift();
    console.log(root.data);
    if (root.left !== null)
      queue.push(root.left);
    if (root.right !== null)
      queue.push(root.right);
  }
}

function maxEle(root) {
  let rootVal, left, right, maxVal = -9999999;
  if (root !== null) {
    rootVal = root.data;
    left = maxEle(root.left);
    right = maxEle(root.right);
    if (left > right) {
      maxVal = left;
    }
    if (right > maxVal) {
      maxVal = right;
    }
    if (rootVal > maxVal) {
      maxVal = rootVal;
    }
  }
  return maxVal;
}

let root = new Node(10);
root.left = new Node(20);
root.right = new Node(130);
root.left.left = new Node(40);
root.left.right = new Node(50);
root.right.left = new Node(60);

console.log(maxEle(root));

