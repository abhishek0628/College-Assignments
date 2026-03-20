SELECT department, COUNT(*)
FROM students
GROUP BY department
HAVING COUNT(*) > 3;
