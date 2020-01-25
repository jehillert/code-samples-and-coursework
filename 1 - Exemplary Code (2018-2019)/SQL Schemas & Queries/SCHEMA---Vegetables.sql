 /*
    systemctl start mysql
    systemctl status mysql\
    sudo mysql -u root<schema.sql
 */
CREATE DATABASE vegetableList;

USE vegetableList;

CREATE TABLE vegetables (
  id INT NOT NULL AUTO_INCREMENT,
  food VARCHAR(255) NOT NULL,
  quantity INT NOT NULL,
  PRIMARY KEY (ID)
);
