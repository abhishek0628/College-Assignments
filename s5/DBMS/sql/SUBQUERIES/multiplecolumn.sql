SELECT column_list
FROM table
WHERE (col1, col2) IN
      (SELECT col1, col2 FROM table WHERE condition);

SELECT name, dept_id, salary
FROM employee
WHERE (dept_id, salary) IN
      (SELECT dept_id, MAX(salary)
       FROM employee
       GROUP BY dept_id);
