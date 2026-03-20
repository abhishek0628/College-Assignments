CREATE VIEW view_name AS
SELECT column1, column2
FROM table_name
WHERE condition;

CREATE VIEW high_salary_employees AS
SELECT emp_id, name, salary
FROM employees
WHERE salary > 50000;

SELECT * FROM high_salary_employees;

-- A View is Updatable if:
-- It is based on one table
-- No GROUP BY
-- No aggregate functions (SUM, COUNT, etc.)
-- No DISTINCT
-- No subqueries
-- No joins

UPDATE high_salary_employees
SET salary = 60000
WHERE emp_id = 101;

-- Non-Updatable Views
-- If the view contains:
-- Joins
-- Aggregates
-- Grouping
-- Calculated columns

CREATE VIEW dept_avg_salary AS
SELECT dept_id, AVG(salary)
FROM employees
GROUP BY dept_id;
