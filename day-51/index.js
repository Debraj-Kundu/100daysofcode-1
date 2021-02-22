let cube = document.getElementById('cube');
let btn = document.getElementsByTagName('button')[0];
cube.style.position = 'relative';
cube.style.top = '10px';
cube.style.left = '10px';
cube.style.width = '100px';
cube.style.height = '100px';
cube.style.backgroundColor = 'red';
cube.style.display = 'none';

btn.onclick = () => {
  //cube.style.left = parseInt(cube.style.left) + 10 + 'px';
  setTimeout(() => {
    cube.style.display = 'block';
  }, 0)
};
btn.onmousedown = () => {
  cube.style.left = parseInt(cube.style.left) + 10 + 'px';
};
