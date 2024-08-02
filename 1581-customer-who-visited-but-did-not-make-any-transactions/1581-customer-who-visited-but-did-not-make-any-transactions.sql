# Write your MySQL query statement below
select customer_id,count(customer_id) as count_no_trans from Visits as v
left join Transactions as t 
ON v.visit_id = t.visit_id
WHERE t.transaction_id IS NULL
GROUP BY v.customer_id
ORDER BY v.customer_id
