let nam = {
  nam: `
  * a
  *b
  *       c
`};

console.log(nam.nam);

let str = 'hello world';
for (let i of str) {
  //console.log(i);
}
console.log(str.indexOf('wor'/*, (optional parameter: starting index)*/));

let st = "As sly as a fox, as strong as an ox";
let target = "as";

let pos = -1;
console.log('indeices: ');
while ((pos = st.indexOf(target, pos + 1)) != -1) {
  console.log(pos);
}

console.log(str.startsWith('hell'));
console.log(str.endsWith('ld'));
console.log(str.slice(0, 5));
//substring() -> like slice but does not allow neg
//substr(start, length)
let x = str.split('o');
console.log(x);

let arr = [10, true, { name: 'name' }, function () { console.log('array'); }]
/**
 * * arr.push(...items) – adds items to the end,
 * * arr.pop() – extracts an item from the end,
 * * arr.shift() – extracts an item from the beginning,
 * * arr.unshift(...items) – adds items to the beginning.
*/
//arr.splice(start, (upTOwhichIndexToRemove, element(s)ToInsert....))
let arr1 = [1, 2, 3, 4, 5, 6, 7, 8];
arr1.splice(3, 1, 69, 59, 79);
console.log(arr1);
//arr1.forEach(alert);
/**
 ** arr.indexOf(item, from) – looks for item starting from index from, and returns the index where it was found, otherwise -1.
 ** arr.lastIndexOf(item, from) – same, but looks for from right to left.
 ** arr.includes(item, from) – looks for item starting from index from, returns true if found.
*/

function comp(a, b) {
  if (a < b) return 1;
  if (a === b) return 0;
  if (a > b) return -1;
}

arr1.sort((a, b) => b - a);
console.log(arr1);

let user = [
  { id: 1, prop: 'a' },
  { id: 2, prop: 'b' },
  { id: 3, prop: 'c' },
];

let axz = user.find((item) => item.id == 2);
let ass = user.filter((item) => item.id < 3);
let abc = arr1.reduce((sum, current) => sum + current, 0);
console.log('reduce: ' + abc);
console.log(ass);

let rules = {
  minAge: 19,
  maxAge: 29,
  canJoin(user) {
    return user.age >= this.minAge && user.age <= this.maxAge;
  }
}

let studs = [
  { age: 15 },
  { age: 22 },
  { age: 24 },
];

let res = studs.filter((stud)=> rules.canJoin(stud));
console.log(res);