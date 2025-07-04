/*
GROUP BY를 사용할 때는 SELECT절에 나오는 컬럼들에 규칙이 있음.
GROUP BY에 포함되지 않은 컬럼을 사용하려면, 반드시 SUM, MAX, COUNT 등과 같은 집계 함수로 감쌀 것
*/
SELECT a.ID, b.FISH_NAME, a.LENGTH
FROM FISH_INFO as a
JOIN FISH_NAME_INFO as b 
on a.FISH_TYPE = b.FISH_TYPE
where (b.fish_type, a.length) in (
    select fish_type, MAX(length)
    from fish_info
    group by fish_type
)
order by a.id asc;