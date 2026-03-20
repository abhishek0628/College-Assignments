SELECT column_name
FROM table_name
WHERE column_name operator (
    SELECT column_name
    FROM table_name
    WHERE condition
);

SELECT name
FROM employee
WHERE salary > (
    SELECT AVG(salary)
    FROM employee
);

SELECT name
FROM employee
WHERE salary = (
    SELECT MAX(salary)
    FROM employee
);

