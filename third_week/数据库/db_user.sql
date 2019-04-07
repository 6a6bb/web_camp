/*
Navicat MySQL Data Transfer

Source Server         : localhost_3306
Source Server Version : 80015
Source Host           : localhost:3306
Source Database       : db_user

Target Server Type    : MYSQL
Target Server Version : 80015
File Encoding         : 65001

Date: 2019-04-07 16:14:14
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for db_user
-- ----------------------------
DROP TABLE IF EXISTS `db_user`;
CREATE TABLE `db_user` (
  `username` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `password` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `right_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`username`),
  KEY `right_id` (`right_id`),
  CONSTRAINT `right_id` FOREIGN KEY (`right_id`) REFERENCES `right` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of db_user
-- ----------------------------
INSERT INTO `db_user` VALUES ('a123456', 'e10adc3949ba59abbe56e057f20f883e', '1');
INSERT INTO `db_user` VALUES ('a1234567', 'fcea920f7412b5da7be0cf42b8c93759', '3');
INSERT INTO `db_user` VALUES ('a12345678', '25d55ad283aa400af464c76d713c07ad', '3');
INSERT INTO `db_user` VALUES ('a123456789', '25f9e794323b453885f5181f1b624d0b', '5');
INSERT INTO `db_user` VALUES ('a132131231214', 'fee6532be045461b6e255cc517f652e4', '5');
