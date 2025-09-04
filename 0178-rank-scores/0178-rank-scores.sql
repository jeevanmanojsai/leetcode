/* Write your PL/SQL query statement below */
select score,
dense_rank() over(order by score desc) as rank
from Scores 
where score is not null;