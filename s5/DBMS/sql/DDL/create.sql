-- create database
-- CREATE DATABASE database_name;
-- CREATE DATABASE IF NOT EXISTS databse_name;
CREATE DATABASE college;
CREATE DATABASE IF NOT EXISTS college;

-- use database
-- USE databasename
USE college;

-- create table
-- CREATE TABLE tablename(
--          columnname1 datatype constraints,
--          .
--          .
--          );
CREATE TABLE student(
    roll_no int primary key,
    name VARCHAR(20) NOT NULL,
    age INT,
    branch VARCHAR(20)
);
create table student(
    roll_no int,
    name varchar(20) not null,
    age int check(age>0)
    branch varchar(20),
    primary key(roll_no)
);
create table courses(
    course_id varchar(20) primary key not null,
    course_name varchar(20),
    roll_no int ,
    foreign_key(roll_no) references student(roll_no)
);
create table account(
    acc_no bigint primary key,
    status varchar default 'active'
);

-- create index
-- CREATE INDEX idx_name ON tablename(columnname);
CREATE INDEX idx_name ON student(name);

-- create view
-- CREATE VIEW views_name AS
-- coomand
CREATE VIEW student_view AS
SELECT roll_no,name from student;