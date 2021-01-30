const link = 'https://jsonplaceholder.typicode.com/users';
let post = 'https://jsonplaceholder.typicode.com/posts';
let txt = document.getElementById('json');
const btn = document.getElementById('btn').addEventListener(
  'click', getUser
);
const btn1 = document.getElementById('form').addEventListener(
  'click', postData
);

function getUser() {
  fetch(link)
    .then((res) => {
      return res.json();
    })
    .then((data) => {
      let output = `<h2>User</h2>`;
      data.forEach(user => {
        output += `
        <div class="container">
          <h3>${user.name}</h3>
          <p>${user.email}</p>
        </div>
        `
      });
      txt.innerHTML = output;
    })
}

function postData(e) {
  e.preventDefault();
  let title = document.getElementById('title').value;
  let body = document.getElementById('body').value;

  fetch(post, {
    method: 'POST',
    headers: {
      'Accept': 'application/json, text/plain, */*',
      'Content-type': 'application/json'
    },
    body: JSON.stringify({ title: title, body: body })
  })
    .then(res => {
      res.json()
    })
    .then(data => {
      console.log(data)
    })
}
