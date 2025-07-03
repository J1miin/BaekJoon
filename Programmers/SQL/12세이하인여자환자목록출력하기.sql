-- METHOD (1)
-- IFNULL(컬럼명, '바꿀이름') as 보일 열 이름
-- NULL 값인 열이면, 내가 다른 값으로 지정해서 바꿀 수 있다.
-- Column의 값이 NULL을 반환할 때, 다른 값으로 출력할 수 있도록 하는 함수

-- METHOD(2)
-- NAME Column이 NULL이 True인 경우 "No name"을, False인 경우는 NAME Column을 출력
-- SELECT IF(IS NULL(NAME), "No name", NAME) as NAME
-- FROM ANIMAL_INS

SELECT PT_NAME,PT_NO,  GEND_CD, AGE, IFNULL(TLNO,'NONE') as TLNO
FROM PATIENT
WHERE GEND_CD = 'W' and AGE <= 12
ORDER BY age desc, pt_name 