--sol1
SELECT DATETIME as 시간 
from animal_ins
order by datetime asc 
limit 1

--sol2
SELECT MIN(DATETIME) as 시간 
from animal_ins
