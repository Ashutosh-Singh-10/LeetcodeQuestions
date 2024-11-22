select machine_id
, round(sum(at)/count(at),3) as processing_time
 from (
    select a.machine_id,a.process_id,b.timestamp-a.timestamp as at
from Activity as a 
inner join 
Activity as b
on a.machine_id=b.machine_id and a.process_id=b.process_id and a.activity_type='start' and a.activity_type is not null
and b.activity_type='end' and b.activity_type is not null
 ) as tab 
 group by machine_id;