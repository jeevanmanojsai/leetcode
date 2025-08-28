select product_id,year as first_year,quantity,price
from Sales
where (product_id,year) in (SELECT  product_id,min(year)
FROM Sales
group by product_id);