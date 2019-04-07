<%@ page language="java" contentType="text/html; charset=utf-8"
	pageEncoding="utf-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>Insert title here</title>
</head>
<body>
	<center>你输入的原密码错误！密码修改失败,稍后跳转回原页面......</center>
	  <center>
				<h2 style="color: red;">${message1 }</h2>
			</center>
	
	<%
		response.setHeader("refresh", "3;url=/huang_login/update.jsp");
	%>

</body>
</html>