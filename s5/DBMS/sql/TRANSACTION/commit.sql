START TRANSACTION;

INSERT INTO student VALUES (101, 'Abhishek', 8.5);

UPDATE student
SET cgpa = 9.0
WHERE roll_no = 101;

COMMIT;
