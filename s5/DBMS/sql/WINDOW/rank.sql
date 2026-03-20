select name,marks,
rank() over(order by marks desc) as rank
from student;