CREATE UNIQUE INDEX idx_email
ON student(email);

CREATE UNIQUE INDEX idx_name_dob
ON student(name, date_of_birth);

DROP INDEX idx_email;
