
-- select name from Employees union select id from EmployeeUNI;
-- select * from 
-- ( select u.unique_id,n.name from Employees as n left join EmployeeUNI as u on n.id=u.id) as a
-- union
-- select null,name from employees where name not in 
-- ( select n.name from Employees as n left join EmployeeUNI as u on n.id=u.id);


SELECT 
    eu.unique_id,
    e.name
FROM Employees e
LEFT JOIN EmployeeUNI eu 
    ON e.id = eu.id;