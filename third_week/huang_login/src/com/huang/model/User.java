package com.huang.model;

public class User {
	private int id;
	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	private String username;
	private String password;
	private int right_id;

	public String getName() {
		return username;
	}

	public void setName(String username) {
		this.username = username;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}
	
	public void setright_id(int right_id) {
		this.right_id = right_id;
	}
	
	public int getright_id() {
		return right_id;
	}

}
