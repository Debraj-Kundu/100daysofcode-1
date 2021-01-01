function marriage(man, woman) {
  woman.husband = man;
  man.wife = woman;

  return {
    father: man,
    mother: woman,
  };
}

let family = marriage(
  { name: 'john', },
  { name: 'milenda' }
);

//console.log(family);

delete family.father;
delete family.mother.husband;
//console.log(family);

let user = {
  name: 'abc',
  age: 10,
  desc() {
    console.log(`my name is ${this.name}`);
  }
};
const speak = () => console.log('hi');
user.speak = speak;
user.speak();
user.desc();

let user1 = { name: 'abc' };
let user2 = { name: 'def' };

function sayName() { 
  console.log(this.name);
}

user1.sayName = sayName;
user2.sayName = sayName;

user1.sayName();
user2.sayName(); 

const fruit = {};
/*optional chaining ?. stops the evaluation if the part 
before ?. is undefined or null and returns that part*/
console.log(fruit?.flavour?.color);

let id = Symbol('id');
let id2 = Symbol('id');

console.log(id === id2);


