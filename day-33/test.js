let arr1 = [1, 2, 3, 4];
let arr2 = [...arr1];
arr1[1] = 10;
console.log("arr1: ", arr1);
console.log("arr2: ", arr2);

const myFun = (callBackFun) => {
  let value = 50;
  callBackFun(value);
};

myFun((value) => {
  console.log(value);
});