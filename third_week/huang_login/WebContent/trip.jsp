<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html lang="en">
<head>
<meta charset="UTF-8">
<title>游客页面</title>

<style>
* {
	margin: 0;
	padding: 0;
}

body {
	background: url(/huang_login/image/bg.jpg) 0 0 no-repeat;
	background-size: 100%;
	-webkit-perspective: 800;
}

li {
	list-style: none;
}

.box {
	width: 200px;
	height: 200px;
	position: relative;
	margin: 300px auto;
	-webkit-transform-style: preserve-3d;
	-webkit-transform: rotateX(13deg);
	-webkit-animation: move 5s linear infinite;
}

.minbox {
	width: 100px;
	height: 100px;
	position: absolute;
	left: 50px;
	top: 50px;
	-webkit-transform-style: preserve-3d;
}

.minbox li {
	width: 100px;
	height: 100px;
	position: absolute;
	left: 0;
	top: 0;
}

.minbox li:nth-child(1) {
	background: url(img/01.png) no-repeat 0 0;
	-webkit-transform: translateZ(50px);
}

.minbox li:nth-child(2) {
	background: url(img/02.png) no-repeat 0 0;
	-webkit-transform: rotateX(180deg) translateZ(50px);
}

.minbox li:nth-child(3) {
	background: url(img/03.png) no-repeat 0 0;
	-webkit-transform: rotateX(-90deg) translateZ(50px);
}

.minbox li:nth-child(4) {
	background: url(img/04.png) no-repeat 0 0;
	-webkit-transform: rotateX(90deg) translateZ(50px);
}

.minbox li:nth-child(5) {
	background: url(img/05.png) no-repeat 0 0;
	-webkit-transform: rotateY(-90deg) translateZ(50px);
}

.minbox li:nth-child(6) {
	background: url(img/06.png) no-repeat 0 0;
	-webkit-transform: rotateY(90deg) translateZ(50px);
}

.maxbox {
	width: 200px;
	height: 200px;
	position: absolute;
	left: 0;
	top: 0;
	-webkit-transform-style: preserve-3d;
}

.maxbox li {
	width: 200px;
	height: 200px;
	background: #fff;
	border: 1px solid #ccc;
	position: absolute;
	left: 0;
	top: 0;
	opacity: 0.2;
	-webkit-transition: all 1s ease;
}

.maxbox li:nth-child(1) {
	-webkit-transform: translateZ(100px);
}

.maxbox li:nth-child(2) {
	-webkit-transform: rotateX(180deg) translateZ(100px);
}

.maxbox li:nth-child(3) {
	-webkit-transform: rotateX(-90deg) translateZ(100px);
}

.maxbox li:nth-child(4) {
	-webkit-transform: rotateX(90deg) translateZ(100px);
}

.maxbox li:nth-child(5) {
	-webkit-transform: rotateY(-90deg) translateZ(100px);
}

.maxbox li:nth-child(6) {
	-webkit-transform: rotateY(90deg) translateZ(100px);
}

.box:hover ol li:nth-child(1) {
	-webkit-transform: translateZ(300px);
}

.box:hover ol li:nth-child(2) {
	-webkit-transform: rotateX(180deg) translateZ(300px);
}

.box:hover ol li:nth-child(3) {
	-webkit-transform: rotateX(-90deg) translateZ(300px);
}

.box:hover ol li:nth-child(4) {
	-webkit-transform: rotateX(90deg) translateZ(300px);
}

.box:hover ol li:nth-child(5) {
	-webkit-transform: rotateY(-90deg) translateZ(300px);
}

.box:hover ol li:nth-child(6) {
	-webkit-transform: rotateY(90deg) translateZ(300px);
}

@
keyframes move { 0%{
	-webkit-transform: rotateX(13deg) rotateY(0deg);
}
100%{
-webkit-transform
:rotateX(13deg)
 
rotateY
(360deg);

		
}
}
</style>

</head>
<body>

	<div class="box">
		<ul class="minbox">
			<li></li>
			<li></li>
			<li></li>
			<li></li>
			<li></li>
			<li></li>
		</ul>
		<ol class="maxbox">
			<li></li>
			<li></li>
			<li></li>
			<li></li>
			<li></li>
			<li></li>
		</ol>
	</div>

	<div style="text-align: center;"></div>
</body>
</html>