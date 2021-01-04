let recipeMap = new Map([
  ['cucumber', 500],
  ['tomatoes', 350],
  ['onion', 50]
]);

recipeMap.set('potato', 30);
for (let vegetable of recipeMap.keys()) {
  //console.log(vegetable); // cucumber, tomatoes, onion
}
//console.log(recipeMap);

let user = {
  name: "John",
  age: 30
};

for (let [key, value] of Object.entries(user)) {
  //console.log(`${key} -> ${value}`);
}
/*
function Sum(...args) {
  let s = 0;
  for (let i of args) {
    s += +i;
  }
  return s;
}

let x = Sum(1, 2, 3, 4, 5, 6);
console.log(x);
*/

function sum(a) {
  return (b) => {
    return a + b;
  }
}

console.log(sum(7)(2));

