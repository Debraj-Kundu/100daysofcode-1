let arr = [1, 2, 3, 6, 5, 4];
let a = arr.map(item => {
  return item += 1;
});
arr = arr.filter(item => {
  if (item !== 3)
    return item;
});
let ans = arr.reduce((sum, item)=> {
  return sum+item*2;
});
arr.forEach(item => {
  console.log(item);
});
/* let a = arr.shift(); */

/* arr.unshift(1, [10, 20, 30]); */
console.log(ans/* .join(" ") */);
/* console.log(arr[1][1]); */