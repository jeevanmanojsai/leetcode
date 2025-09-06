/* Write your PL/SQL query statement below */
with cte AS
(
    SELECT queue.*,
    SUM(weight) OVER(ORDER BY turn) AS running_weight
    FROM queue
)
SELECT person_name FROM cte WHERE turn = (SELECT MAX(turn) FROM cte
WHERE running_weight <= 1000);