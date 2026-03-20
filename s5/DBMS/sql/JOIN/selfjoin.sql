SELECT e1.emp_name AS Employee,
       e2.emp_name AS Manager
FROM Employee e1
LEFT JOIN Employee e2
ON e1.manager_id = e2.emp_id;
