START TRANSACTION;

UPDATE product
SET stock = stock - 5
WHERE pid = 10;

SAVEPOINT sp1;

UPDATE product
SET stock = stock - 100
WHERE pid = 11;   -- mistake

ROLLBACK TO sp1;

COMMIT;
