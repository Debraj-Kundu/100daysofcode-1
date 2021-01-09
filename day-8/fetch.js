/*function getText() {
  fetch('sample.txt')
    .then((res) => {
      return res.text();
    })
    .then((data) => {
      document.getElementById('data').innerHTML = data;
    });
}
document.getElementById('text').addEventListener
  ('click', getText);*/

function parseJson() {
  fetch('https://jsonplaceholder.typicode.com/posts')
    .then(res => {
      return res.json();
    }).then(data => {
      output = '<h3>Posts</h3>';
      data.forEach((post) => {
        output += `
          <div>
            <h4>${post.title}</h4>
            <p>${post.body}</p>
          </div>
          <hr/>
        `
      });
      document.getElementById('data').innerHTML = output;
    })
}




document.getElementById('text').addEventListener
  ('click', parseJson);

document.getElementById('form').addEventListener
  ('click', getForm);
