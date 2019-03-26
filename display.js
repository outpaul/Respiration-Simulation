can = document.querySelector('#canvas');
ctx = can.getContext("2d");
a = document.querySelector('#x');
b = document.querySelector('#y');
var img = new Image();

img.onload = function() {
    ctx.drawImage(img,0,0);
}

img.src = "image.jpeg";

can.addEventListener("mousemove", function (evt) {
    s = can.getBoundingClientRect();
    x = (evt.clientX - s.left + 0.5);
    y = 533 - (evt.clientY - s.top);
    a.innerHTML = x;
    b.innerHTML = y;
});
