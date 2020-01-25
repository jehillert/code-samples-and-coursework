/*mysql -u root <schema.sql*/
DROP DATABASE IF EXISTS `timelockr_dev_db`;
CREATE DATABASE IF NOT EXISTS `timelockr_dev_db`;

USE timelockr_dev_db;

CREATE TABLE IF NOT EXISTS `users` (
  `user_id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  `username` VARCHAR(40) UNIQUE,
  `hash` VARCHAR(172),
  `salt` VARCHAR(100)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `user_settings` (
  `settings_id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  `user_id` INT NOT NULL,
  `card_col_display_config` INT NOT NULL DEFAULT 0,
  `current_theme` VARCHAR(40) DEFAULT 'default',
  FOREIGN KEY fk_user (user_id)
    REFERENCES users(`user_id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `entries` (
  `entry_id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  `user_id` INT NOT NULL,
  `creation_date` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `release_date` DATETIME NOT NULL,
  `description` VARCHAR(100) NOT NULL DEFAULT '',
  `content` VARCHAR(10000) NOT NULL,
  FOREIGN KEY fk_user (user_id)
    REFERENCES users(`user_id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `sessions` (
  `session_id` varchar(128) COLLATE utf8mb4_bin NOT NULL,
  `expires` int(11) unsigned NOT NULL,
  `data` text COLLATE utf8mb4_bin,
  PRIMARY KEY (`session_id`)
) ENGINE=InnoDB;

/* Procedure to show full entries */
-- USE `timelockr_dev_db`;
-- DROP procedure IF EXISTS `ShowEntries`;

-- DELIMITER $$
-- USE `timelockr_dev_db`$$
-- CREATE DEFINER=`root`@`localhost` PROCEDURE `JoinTables`()
-- BEGIN
--   SELECT * FROM timelockr_dev_db.entries
--   LEFT JOIN timelockr_dev_db.users USING (user_id);
-- END;$$

-- DELIMITER ;
