const { setInterval } = require("timers");

let canvas = document.getElementById('canvas');
let render = canvas.getContext('2d');

let x = 100, y = 100;

canvas.style.background = 'orange';
canvas.style.left = '300px';
canvas.style.top = '40px';
canvas.style.position = 'absolute';

/*canvas.addEventListener(
  'keydown', (e) => {
    switch (e.key) {
      case 'ArrowLeft':
        x--;
        break;
      case 'ArrowRight':
        console.log('right');
        break;
      case 'ArrowUp':
        console.log('up');
        break;
      case 'ArrowDown':
        console.log('down');
        break;
    }
  }
)*/

function player(x, y) {
  render.beginPath();
  render.rect(50, 50, 70, 70);
  render.strokeStyle = 'balck';
  render.fillStyle = 'red';
  render.stroke();
  render.fill();
}

/*setInterval(function () {

}, 1000 / 60)*/
player(x, y);