package com.huang.controller;

import com.huang.dao.impl.UserDaoImpl;
import com.huang.util.*;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.huang.model.User;
import com.huang.service.impl.UserServiceImpl;

/**
 * 实现修改密码功能
 */
@WebServlet("/updateservlet")
public class UpdateServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	boolean flat;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public UpdateServlet() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		String username = request.getParameter("username");
		String oldPassword = request.getParameter("oldPassword");
		String newPassword = request.getParameter("newPassword");
		UserServiceImpl userService = new UserServiceImpl();
		if (userService.isRightPassword(oldPassword) == userService.PSWERROR
				|| userService.isRightPassword(newPassword) == userService.PSWERROR) {
			response.sendRedirect("/huang_login/updatefailuer.jsp");
			return;
		}
		String user1 = (String) request.getSession().getAttribute("user");
		if (user1 == null) {
			request.setAttribute("message", "你还未登录！");
			request.getRequestDispatcher("/huang_login/Login.jsp").forward(request, response);
		}
		
		UserDaoImpl d = new UserDaoImpl();
		try {
			flat = d.passwordRight(username, oldPassword);
			
		} catch (Exception e1) {
			
			e1.printStackTrace();
		}
		if (flat == true) {

			User user = new User();
			user.setName(username);
			user.setPassword(oldPassword);		
			try {
				if (d.update(user, newPassword)==true) {
					response.sendRedirect("/huang_login/updatesuccess.jsp");
				} else {
					response.sendRedirect("/huang_login/updatefailuer.jsp");
				}
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			

		} else {
			request.setAttribute("message1", "你输入的原密码错误！");
			response.sendRedirect("/huang_login/updatefailuer2.jsp");
			return;
		}

	}

}
