package com.huang.dao.impl;

import java.sql.*;

import com.huang.dao.*;
import com.huang.model.User;
import com.huang.util.DbUtil;
import com.huang.util.AppMD5Util;
public class UserDaoImpl implements UserDao {
	AppMD5Util til=new AppMD5Util();
	private static DbUtil dbUtil = new DbUtil();
	boolean flat = false;

	// 用户登录
	@Override
	public Boolean login(User user) {			
		Connection con = dbUtil.getCon();
		PreparedStatement pstmt = null;
		try {
			String sql = "select * from db_user where username=? ";
			pstmt = con.prepareStatement(sql);
			pstmt.setString(1, user.getName());
			ResultSet rs = pstmt.executeQuery();
			while (rs.next()) {
				if (user.getPassword().equals(rs.getString("password"))) {
					flat = true;
					break;
				}

			}
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			dbUtil.close(pstmt, con);
		}

		if (flat == true) {
			return true;
		} else {
			return false;
		}
	}
	
	// 修改密码
	@Override
	public boolean update(User user, String newPassword) throws Exception {
		Connection con = dbUtil.getCon();
		PreparedStatement pstmt = null;
		int result = 0;
		try {
			String sql = "update db_user set password=? where username=?";
			pstmt = con.prepareStatement(sql);
			pstmt.setString(1, til.getMD5(newPassword));
			pstmt.setString(2, user.getName());
			result = pstmt.executeUpdate();
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			dbUtil.close(pstmt, con);
		}

		if (result != 0) {
			return true;
		} else {
			return false;
		}
	}

	// 添加用户
	@Override
	public boolean addUser(User user) throws Exception {
		Connection con = dbUtil.getCon();
		PreparedStatement pstmt = null;
		int t = 0;
		try {
			String sql = "insert into db_user(username, password,right_id)values(?, ?,?)";
			pstmt = con.prepareStatement(sql);
			pstmt.setString(1, user.getName());
			pstmt.setString(2, til.getMD5(user.getPassword()));
			pstmt.setInt(3, 5);
			t = pstmt.executeUpdate();
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			dbUtil.close(pstmt, con);
		}
		if (t != 0) {
			return true;
		} else {
			return false;
		}
	}

	// 判断用户是否存在	
	@Override
	public boolean usernameIsExist(String username) throws Exception {
		Connection con = dbUtil.getCon();
		PreparedStatement pstmt = null;
		try {
			String sql = "select * from db_user where username=?";
			pstmt = con.prepareStatement(sql);
			pstmt.setString(1, username);

			if (!pstmt.executeQuery().next()) {
				return false;
			}
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			dbUtil.close(pstmt, con);
		}
		return true;
	}
	
	// 判断输入的原密码是否正确
	@Override
	public boolean passwordRight(String username, String password) throws Exception {
		password=til.getMD5(password);
		Connection con = dbUtil.getCon();
		PreparedStatement pstmt = null;
		try {
			String sql = "select * from db_user where username=username";
			pstmt = con.prepareStatement(sql);
			ResultSet rs = pstmt.executeQuery();
			while (rs.next()) {
				if (password.equals(rs.getString("password"))) {
					
					return true;
				}
			}
		} catch (SQLException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} finally {
			dbUtil.close(pstmt, con);
		}

		return false;

	}
	
	// 判断登录信息是否正确
	@Override
	public boolean LoginRight(String username, String password) throws Exception {
		password=til.getMD5(password);
		boolean t = false;
		Connection con = dbUtil.getCon();
		PreparedStatement pstmt = null;
		String sql = "select * from db_user";
		try {
			pstmt = con.prepareStatement(sql);
			ResultSet rs = pstmt.executeQuery();
			while (rs.next()) {
				if (username.equals(rs.getString("username")) && password.equals(rs.getString("password"))) {
					t = true;
					break;
				}	
			}
		} catch (SQLException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} finally {
			dbUtil.close(pstmt, con);
		}

		return t;

	}

	//获得用户权限类型
	@Override
	public String right(String username) {
		Connection con = dbUtil.getCon();
		PreparedStatement pstmt = null;
		try {
			String sql = "select d.right from db_user e,`right` d where e.right_id=d.id and e.username=? ";
			pstmt = con.prepareStatement(sql);
			pstmt.setString(1, username);
			ResultSet rs = pstmt.executeQuery();
			while (rs.next()) {
				return rs.getString("right");
			}
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			dbUtil.close(pstmt, con);
		}
		return null;

	}
	
	//得到权限id
	public int right_id(String newRight) {
		Connection con = dbUtil.getCon();
		PreparedStatement pstmt = null;
		int right_id=0;
		try {
			String sql = "select e.right_id from db_user e,`right` d where e.right_id=d.id and d.`right`=? ";
			pstmt = con.prepareStatement(sql);
			pstmt.setString(1, newRight);
			ResultSet rs = pstmt.executeQuery();
			rs.next();
				right_id=rs.getInt("right_id");

		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			dbUtil.close(pstmt, con);
		}
		return right_id;
	}

	//修改权限
	@Override
	public boolean changeRight(User user,int right_id) throws Exception {
		Connection con = dbUtil.getCon();
		PreparedStatement pstmt = null;
		int result = 0;
		try {
			String sql = "update db_user set right_id=? where username=?";
			pstmt = con.prepareStatement(sql);
			pstmt.setInt(1, right_id);
			pstmt.setString(2, user.getName());
			result = pstmt.executeUpdate();
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			dbUtil.close(pstmt, con);
		}

		if (result != 0) {
			return true;
		} else {
			return false;
		}
	}

	
}