const fetch = require("node-fetch");
/*let promise = new Promise((resolve, reject) => {
  setTimeout(() => resolve('done'), 2000);
});

promise.then(
  result => console.log(result),
  error => console.log(error)
);
//or

promise.then(console.log);

let promise2 = new Promise((resolve, reject) => {
  setTimeout(() => reject(new Error('Error404')), 3000);
});

promise2.then(
  result => console.log(result),
  error => console.log(error)
);
//or .catch == .then(null, fn)
promise2.finally(() => console.log('loaded')).catch(console.log);
*/
const posts = [
  { 'name': 'post1', 'body': 'post1 body' },
  { 'name': 'post2', 'body': 'post2 body' },
];

function getPost() {
  setTimeout(() => {
    posts.forEach((post) => {
      console.log(`${post.name} : ${post.body} `);
    });
  }, 1000);
}
/**
 * @CALLBACK  
    function createPost(post, callback) {
      setTimeout(() => {
        posts.push(post);
        callback();
      }, 3000);
    }
    createPost({ 'name': 'post3', 'body': 'post3 body' }, getPost);
*/

/**
 * @PROMISE
*/
function createPost(post) {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      posts.push(post);
      const error = false;
      if (!error) {
        resolve();
      } else {
        reject('Error-404');
      }
    }, 3000);
  });
}
/**
 * *createPost({ 'name': 'post3', 'body': 'post3 body' })
 * * .then(getPost)
 * * .catch(error => console.log(error));
*/

/**
 * @Promise .all
 * *const p1 = Promise.resolve('qwerty');
 * *const p2 = 10;
 * *const p3 = new Promise((resolve, reject) => {
 * *  setTimeout(resolve, 2000, 'Done');
 * *});
 * *
 * *const p4 = fetch('https://jsonplaceholder.typicode.com/users').then(obj =>
 * *  obj.json()
 * *);

 * *Promise.all([p1, p2, p3, p4]).then(values => console.log(values));
*/

/**
 * @asyncawait
 * *async function init() {
 * *  await createPost({ 'name': 'post3', 'body': 'post3 body' });
 * *  getPost();
 * *}
 * *init();
*/

async function fetchUser() {
  const obj = await fetch('https://jsonplaceholder.typicode.com/users');
  const data = await obj.json();
  console.log(data);
}
fetchUser();


