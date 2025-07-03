-- group by를 쓴다면, 거기서 쓴 column이 모두 selct에 있어야 한다.

SELECT a.REST_ID, a.REST_NAME, 
a.FOOD_TYPE, a.FAVORITES, a.ADDRESS, ROUND(AVG(b.REVIEW_SCORE),2) as SCORE 
from REST_INFO as a
join REST_Review as b on a.rest_id = b.rest_id
WHERE a.ADDRESS LIKE '서울%'
GROUP BY a.REST_ID, a.REST_NAME, a.FOOD_TYPE, a.FAVORITES, a.ADDRESS
order by score desc, favorites desc