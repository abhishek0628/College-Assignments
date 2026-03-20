SELECT s.sid, s.name, d.dept_name
FROM Student s
LEFT JOIN Department d
ON s.dept_id = d.dept_id

UNION

SELECT s.sid, s.name, d.dept_name
FROM Student s
RIGHT JOIN Department d
ON s.dept_id = d.dept_id;
