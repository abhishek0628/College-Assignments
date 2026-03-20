CREATE TABLE Enrollment (
    student_id INT,
    course_id INT,
    PRIMARY KEY (student_id, course_id)
);
-- add primary key exclusively
ALTER TABLE Student
ADD CONSTRAINT pk_student PRIMARY KEY (id);
