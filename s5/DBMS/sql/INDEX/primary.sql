CREATE TABLE student (
    roll_no INT PRIMARY KEY,
    name VARCHAR(50),
    dept VARCHAR(20)
);

-- roll_no becomes the primary key

-- DBMS creates a primary index on roll_no

-- Data is stored in sorted order of roll_no (clustered behavior)