SELECT column_name, AGG_FUNC(column)
FROM table_name
GROUP BY column_name;

SELECT dept, COUNT(*) 
FROM student
GROUP BY dept;
