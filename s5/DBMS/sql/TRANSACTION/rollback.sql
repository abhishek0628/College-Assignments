START TRANSACTION;

UPDATE account
SET balance = balance - 1000
WHERE acc_no = 1;

-- Suppose this fails (wrong account number)
UPDATE account
SET balance = balance + 1000
WHERE acc_no = 999;

ROLLBACK;
