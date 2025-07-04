/*
COUNT(name) :	NULL 제외하고 name 개수
COUNT(*)	: NULL 포함, 행 개수
COUNT(DISTINCT name) :	중복 제거하고 NULL 제외한 name 개수
COUNT(DISTINCT ...) + WHERE name IS NOT NULL : 명확하게 NULL 제거 후 집계 
3이나 4번이나 결과는 동일하지만 4번 방법은 조금더 명확하게 명시해준 것 뿐!
*/
SELECT count(distinct name) as count
from animal_ins
where name is not null