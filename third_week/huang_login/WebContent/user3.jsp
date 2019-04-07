<%@ page language="java" contentType="text/html; charset=utf-8"
	pageEncoding="utf-8" %>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>用户界面</title>
<style type="text/css">
body, ul, li {
	margin: 0;
	padding: 0;
}

li {
	list-style: none;
}

.main {
	height: 613px;
	background: url("/huang_login/image/modifpsw.jpg") no-repeat 0 -150px;
}

.main-con {
	height: 100%;
	margin: 0 20%;
	position: relative;
}

ul {
	top: 150px;
	position: absolute;
}

ul li {
	text-align: center;
	width: 150px;
	height: 50px;
	font: 18px/50px 微软雅黑;
	color: #72F4FD;
	border: #fff 1px solid;
}

ul li:hover {
	color: #fff;
	border: #72F4FD 1px solid;
}

.login {
	height: 50px;
	width: 150px;
	color: #72F4FD;
	font: 18px/50px 微软雅黑;
	text-align: center;
	position: absolute;
	top: 20px;
	right: 0px;
	border: #fff 1px solid;
}

.login:hover {
	color: #fff;
	border: #72F4FD 1px solid;
}
</style>
</head>
<body>
	<c:if test="${empty user }">
		<center>
			<h1>您还未登录，不能访问此页面</h1>
			<h3>
				点击<a href="/huang_login/Login.jsp">登录</a>或者<a
					href="/huang_login/Register.jsp">注册</a>
			</h3>
		</center>
	</c:if>
	<c:if test="${not empty user }">           
		<div class="main">
			<div class="main-con">
				<ul>
					<li><a href="https://baidu.com/">百度一下</a></li>
					<li><a href="/huang_login/update.jsp">修改密码</a></li>
					<li><a href="quit.jsp">退出</a></li>
				</ul>
				<div class="login">用户</div>
			</div>
		</div>
	</c:if>
</body>
</html>