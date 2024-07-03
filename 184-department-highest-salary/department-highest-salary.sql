/* Write your T-SQL query statement below */

select 
d.name as department,e.name as employee ,e.salary 
from 
employee as e 
left join 
department as d 
on 
e.departmentid=d.id where salary =(select max(salary) from employee where departmentId=e.departmentid);
