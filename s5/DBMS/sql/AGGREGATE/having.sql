SELECT column, AGG_FUNC(column)
FROM table
GROUP BY column
HAVING condition;

SELECT dept, AVG(marks)
FROM student
GROUP BY dept
HAVING AVG(marks) > 70;
