SELECT column FROM table1
UNION
SELECT column FROM table2;
SELECT city FROM customers
UNION
SELECT city FROM suppliers;


SELECT column FROM table1
UNION ALL
SELECT column FROM table2;
SELECT city FROM customers
UNION ALL
SELECT city FROM suppliers;


SELECT column FROM table1
INTERSECT
SELECT column FROM table2;
SELECT student_id FROM exam1
INTERSECT
SELECT student_id FROM exam2;


SELECT column FROM table1
EXCEPT
SELECT column FROM table2;
SELECT student_id FROM exam1
EXCEPT
SELECT student_id FROM exam2;


SELECT student_id FROM exam1
WHERE student_id IN (
    SELECT student_id FROM exam2
);


SELECT city FROM customers
UNION
SELECT city FROM suppliers
ORDER BY city;
