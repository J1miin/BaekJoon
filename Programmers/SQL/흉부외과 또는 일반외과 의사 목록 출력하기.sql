-- DATE_FORMAT(열, 출력 날짜 형식) as 열 이름
-- 이 때, 출력 날짜형식에 ''를 해줘야 한다.
-- where MCDP_CD in ('CS','GS') 처럼 in으로 확인할 떄 그냥 ,로 연결하면 된다. 
SELECT DR_NAME, DR_ID,MCDP_CD, DATE_FORMAT(HIRE_YMD,'%Y-%m-%d') as HIRE_YMD
from DOCTOR
where MCDP_CD in ('CS','GS')
order by hire_ymd desc, dr_name asc