-- keeps in order
SELECT column1, column2
FROM table
ORDER BY column1;

SELECT * FROM students
ORDER BY marks DESC;

SELECT name, age, marks
FROM student
ORDER BY age ASC, marks DESC;
-- Meaning:
-- Sort by age
-- If age is same, sort by marks

SELECT name, marks, age
FROM student
ORDER BY 2 DESC;

SELECT name, marks + 5 AS adjusted_marks
FROM student
ORDER BY adjusted_marks DESC;

SELECT age, AVG(marks) AS avg_marks
FROM student
GROUP BY age
ORDER BY avg_marks DESC;

