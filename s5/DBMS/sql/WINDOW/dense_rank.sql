select name,marks,
dense_rank() over(order by marks desc) as rank
from student;