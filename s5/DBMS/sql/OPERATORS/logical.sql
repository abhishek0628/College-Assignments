SELECT * 
FROM employee
WHERE department = 'IT' AND salary > 60000;


SELECT * 
FROM employee
WHERE department = 'HR' OR department = 'Admin';


SELECT * 
FROM employee
WHERE NOT department != 'Finance';
