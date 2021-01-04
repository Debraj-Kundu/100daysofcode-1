//caching

function increment(n) {
  return n + 1;
}

function funcWrapper(func) {
  let cache = new Map();

  return (arg) => {
    if (cache.has(arg)) {
      return cache.get(arg);
    }
    let result = func(arg);
    cache.set(arg, result);
    return result;
  };
}

increment = funcWrapper(increment);
console.log(increment(1));
/*
function say() {
  return console.log(this.name);
}

let user = { name: "John" };
let admin = { name: "Admin" };

say.call(user);
say.call(admin);
*/

let operation = {
  someMethod() {
    return 1;
  },
  increment(n) {
    return n + 1;
  }
};

function funcWrapper(func) {
  let cache = new Map();

  return (arg) => {
    if (cache.has(arg)) {
      return cache.get(arg);
    }
    let result = func.call(this, arg);
    cache.set(arg, result);
    return result;
  };
}

operation.increment = funcWrapper(operation.increment);
console.log(operation.increment(2));

let operation1 = {
  someMethod() {
    return 1;
  },
  show(min, max) {
    console.log(`min: ${min}, max: ${max}`);
    return min + max;
  }
};

function funcWrapper1(func, hash) {
  let cache = new Map();
  return function () {
    let key = hash(arguments);
    if (cache.has(key)) {
      return cache.get(key);
    }
    let result = func.call(this, ...arguments);
    cache.set(key, result);
    return result;
  };
}

function hash(args) {
  return [].join.call(arguments);
}

operation1.show = funcWrapper1(operation1.show, hash);

console.log(operation1.show(3, 5));
/**
 * * func.call(reffer, arg1, arg2);
 * * func.apply(reffer, [arg1, arg2]);
 * * func.bind(this);
*/

let user = {
  name: 'tenten',
  method() {
    console.log(this.name);
  }
}

//setInterval(user.method, 1000);//undefined
setTimeout(() => user.method(), 1000);

class Vehical {
  constructor() {
    this.engine = null;
    this.fuel = null;
    this.color = null;
    this.cost = null;
  }

  show() {
    console.log(`engine: ${this.engine}, fuel: ${this.fuel}, color: ${this.color}, cost: ${this.cost}`);
  }

}

class Car extends Vehical {
  constructor() {
    super();
    this.name = 'ferrari';
  }
  detail() {
    this.color = 'red';
    this.engine = 'V8';
    this.fuel = 'petrol';
    this.cost = '2.3$';
    super.show();
  }
}

let car1 = new Car();
console.log('------------------------');
car1.detail();
