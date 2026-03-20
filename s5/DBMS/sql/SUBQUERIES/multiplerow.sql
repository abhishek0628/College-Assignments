-- IN
-- Syntax
SELECT column
FROM table
WHERE column IN (SELECT column FROM table);

SELECT name
FROM employee
WHERE dept_id IN (
    SELECT dept_id
    FROM department
    WHERE location = 'Chennai'
);

-- ANY
SELECT column
FROM table
WHERE column operator ANY (subquery);

SELECT name
FROM employee
WHERE salary > ANY (
    SELECT salary
    FROM employee
    WHERE dept_id = 10
);

-- ALL
SELECT column
FROM table
WHERE column operator ALL (subquery);

SELECT name
FROM employee
WHERE salary > ALL (
    SELECT salary
    FROM employee
    WHERE dept_id = 10
);

-- EXISTS
SELECT name
FROM employee e
WHERE EXISTS (
    SELECT 1
    FROM department d
    WHERE d.dept_id = e.dept_id
);

