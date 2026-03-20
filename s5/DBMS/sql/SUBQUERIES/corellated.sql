SELECT column
FROM table1 t1
WHERE condition OPERATOR (
    SELECT aggregate_function(column)
    FROM table2 t2
    WHERE t2.column = t1.column
);

SELECT e.name
FROM employee e
WHERE e.salary >
      (SELECT AVG(salary)
       FROM employee
       WHERE dept_id = e.dept_id);
