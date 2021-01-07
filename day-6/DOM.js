{/*document.body.style.background = "white";
//setTimeout(()=> document.body.style.background = "", 2000);

let elem = document.querySelectorAll('ul > li:last-child');
for (let e of elem) {
  alert(e.innerHTML);
}*/}


$(document).ready(function () {
  var cube = $('#cube');
  cube.css({ 'height': '100px', 'width': '100px', 'background-color': 'red' });
  cube.mouseover(() => {
    cube.hide();//fadein/out, slide
  });
  cube.mouseout(() => {
    cube.show();
  });
  cube.click(() => {
    cube.animate({ left: '500px' }, () => {
      cube.animate({ bottom: '300px' });
    });
  });
  cube.hover(() => {
    cube.hide();
  },
    () => {
      cube.show();
    });

});
