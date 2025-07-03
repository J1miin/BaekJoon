-- UNION : 두 개 이상의 SELECT 결과를 수직으로 합친다. (행 기준으로) - 중복제거함
-- UNION ALL 중복 제거안함
-- 두 SELECT문의 컬럼 개수, 순서, 타입이 일치해야 한다.
-- ORDER BY는 전체 UNION 마지막에만 가능하다.
    SELECT DATE_FORMAT(sales_date,'%Y-%m-%d') as sales_date, product_id, user_id, sales_amount
    from online_sale 
    where sales_date like '2022-03-%'
union
    SELECT DATE_FORMAT(sales_date,'%Y-%m-%d') sales_date, 
    product_id, NULL as user_id, sales_amount
    from offline_sale 
    where sales_date like '2022-03-%'
order by sales_date asc, product_id, user_id