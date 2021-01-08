const names = ['abc', 'def', 'ghi'];

for (let e of names) {
  //console.log(e);
}
const idx1 = names.findIndex((e) => e === 'def');
//console.log(idx1);

names.splice(0, 1, 'dk');
console.log(names)
//--------------------------------------------------------
const id = new Set();//can pass an array [1,1,2,3]
id.add(1);
id.add(1);
id.add(10);
for (let e of id) {
  //console.log(e);
}
console.log(id.has(10));
id.delete(1);
console.log(id);

//--------------------------------------------
const data = new Map();

data.set('name', 'dk');
data.set('age', 19);
console.log(data.get('name'));
data.delete('age');
console.log(data);

//----------------------------------------------
class LinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
  }
  apppend(val) {
    const newNode = { value: val, next: null };
    if (this.tail) {
      this.tail.next = newNode;
    }
    this.tail = newNode;
    if (!this.head) {
      this.head = newNode;
    }
  }
  prepend(val) {
    const newNode = { value: val, next: this.head };
    this.head = newNode;
    if (!this.tail) {
      this.tail = newNode;
    }
  }
  deleteElem(val) {
    if (!this.head) {
      return;
    }
    while (this.head && this.head.value === val) {
      this.head = this.head.next;
    }

    let curr = this.head;
    while (curr.next) {
      if (curr.next.value === val) {
        curr.next = curr.next.next;
      } else {
        curr = curr.next;
      }
    }

    if (this.tail.value === val) {
      this.tail = curr;
    }
  }
  printList() {
    const arr = [];
    let curr = this.head;

    while (curr) {
      arr.push(curr.value);
      curr = curr.next;
    }
    return arr;
  }
  find(val) {
    if (!this.head) {
      return;
    }
    let curr = this.head;
    while (curr) {
      if (curr.value === val) {
        return curr;
      }
      curr = curr.next;
    }
    return null;
  }
}

const l1 = new LinkedList();
l1.apppend(1);
l1.apppend(2);
l1.apppend(3);
l1.apppend(7);
l1.prepend(-1);
l1.deleteElem(3);
const ans = l1.printList();
console.log(ans);

