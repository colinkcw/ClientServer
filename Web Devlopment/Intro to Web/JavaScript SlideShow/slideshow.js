NewImg = new Array (
"images/img1.jpg",
"images/img2.jpg",
"images/img3.jpg",
"images/img4.jpg",
"images/img5.jpg",
"images/img6.jpg",
"images/img7.jpg",
"images/img8.jpg",
"images/img9.jpg",
"images/img10.jpg"

);
var ImgNum = 0;
var ImgLength = NewImg.length - 1;
var interval;
var stop = false;
var run;
var prev;

function random(){
var img = new Image();
prev = ImgNum;
ImgNum = Math.floor(Math.random() * 9);
if (ImgNum == prev) {random()}
DisNum = ImgNum + 1;
 img.src =  NewImg[ ImgNum ] ;
    document.slideshow.src = img.src;
	document.getElementById("imgName").innerHTML = "img" + DisNum + ".jpg";
  }
function chgImg(direction) {
if (document.images) {
ImgNum = ImgNum + direction;
DisNum = ImgNum + 1;
document.getElementById("imgName").innerHTML = "img" + DisNum + ".jpg";
if (ImgNum > ImgLength) {
ImgNum = 0;
DisNum = ImgNum + 1;
document.getElementById("imgName").innerHTML = "img" + DisNum + ".jpg";
}
if (ImgNum < 0) {
ImgNum = ImgLength;
DisNum = ImgNum + 1;
document.getElementById("imgName").innerHTML = "img" + DisNum + ".jpg";
}
document.slideshow.src = NewImg[ImgNum];
   }
}

function changeBackground(color){
document.bgColor = document.getElementById('color').value;
}

function first(){
var img = new Image();
ImgNum = 0;
DisNum = ImgNum + 1;
 img.src =  NewImg[ ImgNum ] ;
    document.slideshow.src = img.src;
	document.getElementById("imgName").innerHTML = "img" + DisNum + ".jpg";
  }
  function last(){
  var img = new Image ();
  ImgNum = 9
  DisNum = ImgNum + 1;
  img.src = NewImg [ImgNum];
  document.slideshow.src = img.src;
  document.getElementById("imgName").innerHTML = "img" + DisNum + ".jpg";
  }
  

	/*var rangeInput = document.getElementById("runvalue");

	rangeInput.onchange = function () {
		runValue.innerText = this.value;
	}
 var interval = rangeInput*1000;*/
var interval = 700;
function auto() {
if (stop == true) {
stop = false;
window.clearInterval(run);
}
else if (stop == false) {
stop = true;
run = setInterval("chgImg(1)", interval);
   }
}