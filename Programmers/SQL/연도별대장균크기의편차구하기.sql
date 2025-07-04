-- select에서 alias한 것들은 반영이 가장 늦기 때문에 join의 on에서 쓸 수 없다.
-- SELECT에서 만든 alias는 ON, WHERE, GROUP BY에서 사용할 수 없다.
-- ORDER BY에서는 SELECT alias를 사용할 수 있다.
-- 서브쿼리 안에서 만든 alias는 ON절 등에서도 사용할 수 있다.
select YEAR(DIFFERENTIATION_DATE) as year, 
b.maxsize-e.size_of_colony as YEAR_DEV, ID
from ecoli_data as e
join 
(select Year(DIFFERENTIATION_DATE)as year, max(size_of_colony) as maxsize
from ecoli_data
group by year) as b
on YEAR(e.DIFFERENTIATION_DATE) = b.year
order by YEAR(e.DIFFERENTIATION_DATE), YEAR_dev 