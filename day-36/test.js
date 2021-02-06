const prompt = require('prompt-sync')();
let t = prompt();
while (t--) {
  const p = prompt();
  const n = prompt();
  let arr = [];
  for (let i = 0; i < n; i++) {
    arr[i] = prompt();
  }
  arr.forEach(item => console.log(item));
}
