SELECT * FROM table_name
WHERE column_name IN (value1, value2, ...);
SELECT * FROM student
WHERE branch IN ('CSE', 'ECE', 'IT');


SELECT * FROM table_name
WHERE column_name NOT IN (value1, value2, ...);
SELECT * FROM student
WHERE branch NOT IN ('MECH', 'CIVIL');


SELECT * FROM table_name
WHERE column_name BETWEEN low AND high;
SELECT * FROM employee
WHERE salary NOT BETWEEN 30000 AND 70000;

SELECT * FROM student WHERE name LIKE 'A%';
SELECT * FROM student WHERE name LIKE '_a%';


SELECT * FROM student WHERE name NOT LIKE 'A%';


SELECT * FROM employee WHERE bonus IS NULL;


SELECT * FROM employee WHERE bonus IS NOT NULL;


SELECT * FROM table1
WHERE EXISTS (SELECT * FROM table2 WHERE condition);
SELECT * FROM employee e
WHERE EXISTS (
    SELECT * FROM department d
    WHERE e.dept_id = d.dept_id
);


SELECT * FROM employee
WHERE salary > ANY (
    SELECT salary FROM employee WHERE dept = 'HR'
);


SELECT * FROM employee
WHERE salary > ALL (
    SELECT salary FROM employee WHERE dept = 'HR'
);





