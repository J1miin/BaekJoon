-- left join  (A-B)
SELECT a.ANIMAL_ID, a.NAME
from animal_outs a
left join animal_ins b
on a.animal_id = b.animal_id
where b.animal_id is null
