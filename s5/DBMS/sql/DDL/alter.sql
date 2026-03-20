-- add column
-- ALTER TABLE tablename;
-- ADD columnname contraints;
ALTER TABLE student;
ADD email VARCHAR(50);

-- modify column
-- ALTER TABLE tablename;
-- MODIFY columnname contraints;
ALTER TABLE student;
MODIFY age INT NOT NULL;

-- rename a column
-- ALTER TABLE tablename;
-- RENAME COLUMN oldtablename to newtablename;
ALTER TABLE student;
RENAME COLUMN branch to department;

-- drop a column
-- ALTER TABLE tablename;
-- DROP coumnname;
ALTER TABLE student;
DROP email;

show create table courses;
alter table courses
drop foreign key courses_ibfk_1;

alter table courses
add constraint courses_ibfk_1
foreign key(roll_no)
references student(roll_no)
on delete cascade
on update cascade;

alter table student
add constraint chk_age check(age>0 and age<100);


