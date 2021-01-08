const cube = document.getElementById('cube');
const move = 10;

window.addEventListener('load', () => {
  cube.style.position = 'absolute';
  cube.style.left = 0;
  cube.style.top = 0;
});

window.addEventListener('keydown', (e) => {
  switch (e.key) {
    case 'ArrowLeft':
      cube.style.left = parseInt(cube.style.left) - move + 'px';
      break;
    case 'ArrowRight':
      cube.style.left = parseInt(cube.style.left) + move + 'px';
      break;
    case 'ArrowUp':
      cube.style.top = parseInt(cube.style.top) - move + 'px';
      break;
    case 'ArrowDown':
      cube.style.top = parseInt(cube.style.top) + move + 'px';
      break;
  }
});

window.addEventListener('keyup', (e) => {
  switch (e.key) {
    case 'ArrowLeft':
      cube.style.background = 'yellow';
      break;
    case 'ArrowRight':
      cube.style.background = 'red';
      break;
    case 'ArrowUp':
      cube.style.background = 'orange';
      break;
    case 'ArrowDown':
      cube.style.background = 'blue';
      break;
  }
});


