class Node {
  constructor(element) {
    this.element = element;
    this.next = null;
  }
}
class LList {
  constructor() {
    this.head = new Node("head");
  }
  find(item) {
    var currNode = this.head;
    while(currNode.element != item) {
      currNode = currNode.next;
    }
    return currNode;
  }
  insert(newElement, item) {
    var newNode = new Node(newElement);
    var current = this.find(item);
    newNode.next = current.next;
    current.next = newNode;
  }
  display() {
    var currNode = this.head;
    while (!(currNode.next == null)) {
      console.log(currNode.next.element);
      currNode = currNode.next;
    }
  }
}



// main program
var cities = new LList();
cities.insert("Conway", "head");
cities.insert("Russellville", "Conway");
cities.insert("Alma", "Russellville");
cities.display()