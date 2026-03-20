SELECT s.sid, s.name, d.dept_name
FROM Student s
INNER JOIN Department d
ON s.dept_id = d.dept_id;
