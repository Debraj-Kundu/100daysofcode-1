
function showPost() {
  fetch('https://jsonplaceholder.typicode.com/posts')
  .then(res => res.json())
  .then(posts => {
    let output = '<h2>Cards</h2>';
    posts.forEach((post) => {
      output += `
        <div>
          <h2>${post.title}</h2>
          <p>${post.body}</p>
        </div>
      `
    });
    document.getElementById('data').innerHTML = output;
  })
}

function getPost(e) {
  e.preventDefault();
  let title = document.getElementById('title').value;
  let body = document.getElementById('body').value;

  fetch('https://jsonplaceholder.typicode.com/posts', {
    method: 'POST',
    headers: {
      'Accept': 'application/json, text/plain */*',
      'Content-type': 'application/json'
    },
    body: JSON.stringify({ title: title, body: body })
  })
    .then(res => res.json())
    .then(data => console.log(data))

}



document.getElementById('btn').addEventListener(
  'click', getPost
);
document.getElementById('btn').addEventListener
  ('click', showPost);