select name ,marks,
row_number() over(order by marks desc) as rank
from student;
