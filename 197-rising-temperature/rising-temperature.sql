select Id from weather as a where 
a.temperature> ( select max(temperature)
 from weather as b where Datediff(a.recordDate,b.recordDate)=1
);