let str1 = 'str1';
let str2 = `${str1} str2`;
console.log(str2);
//typeof
console.log(typeof 0);
console.log(typeof 10n);
console.log(typeof Symbol('a'));
console.log(typeof null);
console.log(typeof Math);
console.log(typeof alert);

// alert(), prompt(), confirm()
//confirm('question');
/**
 * *Type conversion
 * String()
 * Number()
 * Boolean()
 */

//string with binary +
console.log('1' + 2);//'12'
console.log(2 + 2 + '1');//'41'
console.log('1' + 2 + 2);//'122'
//string with binary - and others
console.log('1' - 2);//-1
console.log(2 - 2 - '1');//-1
console.log('1' - 2 - 2);//-3
// Converts non-numbers
console.log(+true); // 1
console.log(+"");   // 0

// assignment operator = returns a value
let a = 1;
let b = 2;
let c = 3 - (a = b + 1);
//The call a = b writes the value into a and then returns it
console.log('a: ' + a);
console.log('c: ' + c);

/*
"" + 1 + 0 = "10" 
"" - 1 + 0 = -1 
true + false = 1
6 / "3" = 2
"2" * "3" = 6
4 + 5 + "px" = "9px"
"$" + 4 + 5 = "$45"
"4" - 2 = 2
"4px" - 2 = NaN
7 / 0 = Infinity
"  -9  " + 5 = "  -9  5" 
"  -9  " - 5 = -14 
null + 1 = 1 
undefined + 1 = NaN 
" \t \n" - 2 = -2 
*/

//nullish coalescing operator
let x;
console.log(x ?? 'Not defined');
//function declaration
function fun() {
  console.log('function declaration');
}
//function expression
const foo = () => console.log('function expression');
fun();
foo();

/* -----------------------------*/
//objects

let person = {
  name: 'abc',
  age: 19,
};
person.gender = 'M';
delete person.age;
//to add multiword property
person['favourite food'] = 'chicken';
console.log(person);

let fruit = 'apple';

let bag = {
  [fruit]: 5,
}
console.log(bag);

function makeUser(name, age) {
  return {
    name,
    age,
  };
}

let user = makeUser('abc', 10);
console.log(user);
console.log("age" in user);
console.log("food" in user);

