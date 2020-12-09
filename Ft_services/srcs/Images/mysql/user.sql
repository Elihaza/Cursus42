CREATE DATABASE wordpress;
CREATE USER 'username'@'%' IDENTIFIED BY "password";
GRANT ALL PRIVILEGES ON wordpress.* TO 'username'@'%';
FLUSH PRIVILEGES;