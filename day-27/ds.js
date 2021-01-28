class Stack {
  constructor() {
    this.dataStore = [];
    this.top = 0;
  }
  push(val) {
    this.dataStore[this.top++] = val;

  }
  pop() {
    this.top--;
    this.dataStore[this.top + 1];
  }
};

class Queue {
  constructor() {
    this.dataStore = [];
  }
  enqueue(element) {
    this.dataStore.push(element);
  }
  dequeue() {
    return this.dataStore.shift();
  }
  front() {
    return this.dataStore[0];
  }
  back() {
    return this.dataStore[this.dataStore.length - 1];
  }
  toString() {
    var retStr = "";
    for (var i = 0; i < this.dataStore.length; ++i) {
      retStr += this.dataStore[i] + "\n";
    }
    return retStr;
  }
  empty() {
    if (this.dataStore.length == 0) {
      return true;
    }
    else {
      return false;
    }
  }
}


/* let s = new Stack();
s.push(1);s.push(3);s.push(2);s.push(4);
console.log(s.top);
s.pop();
console.log(s.top);
s.pop();
console.log(s.top); */

/* let q = new Queue();
q.enqueue(1);q.enqueue(3);q.enqueue(2);q.enqueue(4);
console.log(q.front());
q.dequeue();
console.log(q.front());
q.dequeue();
console.log(q.front());
q.dequeue(); */
let fs = require("fs");

function getDancers(male, female) {
  let names = fs.readFileSync('./day-27/task.txt', 'utf-8').split('\n');

  names.forEach((item) => {
    let dancer = item.split(' ');
    let sex = dancer[0];
    dancer = dancer[1];
    if (sex == 'F')
      female.enqueue({ dancer, sex });
    else
      male.enqueue({ dancer, sex });
  })
}
function dance(males, females) {
  console.log("The dance partners are: \n");
  while (!females.empty() && !males.empty()) {
    person = females.dequeue();
    console.log("Female dancer is: " + person.dancer);
    person = males.dequeue();
    console.log(" and the male dancer is: " + person.dancer);
  }
  console.log();
}
// test program
let maleDancers = new Queue();
let femaleDancers = new Queue();
getDancers(maleDancers, femaleDancers);
dance(maleDancers, femaleDancers);
if (!femaleDancers.empty()) {
  console.log("Ms." + femaleDancers.front().dancer + " is waiting to dance.");
}
if (!maleDancers.empty()) {
  console.log("Mr." + maleDancers.front().dancer + " is waiting to dance.");
}

class PriorityQueue {
  constructor() {
    this.dataStore = [];
  }
  enqueue(val) {
    this.dataStore.push(val);
  }
  dequeue() {
    let priority = this.dataStore[0].code;
    for (var i = 1; i < this.dataStore.length; ++i) {
      if (this.dataStore[i].code < priority) {
        priority = i;
      }
    }
    return this.dataStore.splice(priority, 1);
  }
  front() {
    return this.dataStore[0];
  }
  empty() {
    if (this.dataStore.length == 0) {
      return true;
    }
    else {
      return false;
    }
  }
};

