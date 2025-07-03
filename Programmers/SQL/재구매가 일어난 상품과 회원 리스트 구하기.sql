-- GROUP BY 한 개 이상의 컬럼도 묶어서 group by 수행 가능하다. 
-- group by의 결과는 한 행으로 중복 제거되어서 나오는데,
-- having COUNT(*) 값은 그 그룹에 속한 행 개수를 계산한다. (중복된 행 수를 찾을 수 있다)

SELECT USER_ID, PRODUCT_ID
FROM ONLINE_SALE
group by user_id, product_id
having count(*)>=2
order by user_id, product_id desc
