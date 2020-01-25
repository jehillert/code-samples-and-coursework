CREATE DATABASE pomeranian_database;

USE pomeranian_database;

CREATE TABLE pomeranians (
  id int NOT NULL AUTO_INCREMENT,
  name varchar(50) NOT NULL,
  description varchar(200) NOT NULL,
  PRIMARY KEY (ID)
);
