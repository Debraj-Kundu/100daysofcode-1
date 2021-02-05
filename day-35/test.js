let div = document.getElementById('cube');
div.style.position = 'relative';
div.style.left = '0px';
window.addEventListener('load', () => {
  cube.style.position = 'absolute';
  cube.style.left = 0;
  cube.style.top = 0;
});
document.getElementById('btn').onclick = () => {
  div.style.left = parseInt(imgObj.style.left) + 10 + 'px';
};
