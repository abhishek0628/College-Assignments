-- UPDATE tablename
-- SET columnname=data;

SET SQL_SAFE_UPDATES=0;--to update the table set
SET SQL_SAFE_UPDATES=1;--again set to 1
UPDATE student
SET age=33
WHERE name='rayn';