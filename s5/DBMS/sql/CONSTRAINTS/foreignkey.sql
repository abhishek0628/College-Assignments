-- base table/refeerenced table
create table Customer(
    customer_id int primary key,
    customer_name varchar(20) not null,
    age int 
);

-- derived table/referencing table
CREATE TABLE Orders (
    order_id INT PRIMARY KEY,
    customer_id INT,
    FOREIGN KEY (customer_id) REFERENCES Customer(customer_id)
);
