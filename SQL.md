# SQL Basic

## GROUP BY
```sql
SELECT COL1,COL2 FROM TAB1 GROUP BY COL2 HAVING SUM(COL1)>3000;
```

## 두 개 이상의 열에 대해 GROUP BY
```sql
SELECT COL1, COL2, COUNT(*) FROM TAB1 GROUP BY COL1, COL2;
```
같은 COL1-COL2 조합에 대해서 그룹화가 가능

## JOIN
INNER JOIN, LEFT OUTER JOIN, RIGHT OUTER JOIN, FULL OUTER JOIN, NATURAL JOIN
```sql
SELECT * FROM tabA JOIN tabB ON A.col = B.col WHERE <condition>;
SELECT * FROM tabA, tabB WHERE A.col=B.col;
```
two sql stmts are EXACTLY THE SAME.

## MySQL Functions
```
# 수학함수
ABS, MOD, POW, SQRT, CEILING, FLOOR, ROUND, TRUNCATE, RAND
ROUND, TRUNCATE: 자릿수를 지정할 수 있음. ex. TRUNCATE(3.567,2) = 3.56

MAX, MIN(column)

GREATEST, LEAST(array of numbers)

# 문자열 함수
ASCII(CHAR to ASCII), CHAR(ASCII to CHAR)

BIT_LENGTH(비트수), CHAR_LENGTH(문자의 개수, 중요), LENGTH(바이트 수)

CONCAT, CONCAT_WS (WS는 구분자를 이용해 문자를 합친다.)
ex. CONCAT_WS('-','2020','01','01') = 2020-01-01

INSTR(str1, str2) : str1에서 str2를 찾는다. 1부터 시작하는 index 반환, 없으면 0 반환 ex. INSTR("abcdefg","de") = 4

=> LIKE 로 존재 유무 파악 가능 COL1 LIKE '%ABC%'

FORMAT(targetNum, roundcut) : 소숫점은 roundcut까지 반올림, 그 위는 세자리수 컴마로 구분해줌 (1,234,567)
LPAD,RPAD(문자열, 원하는길이, 패딩문자)
LTRIM,RTRIM,TRIM(공백제거)
TRIM(BOTH 'a' FROM 'aababaa')

LEFT,RIGHT(str, len) : 왼쪽 오른쪽에서 len만큼 가져온다고
MID(str,start,len)
LOWER,UPPER,LCASE,UCASE(str) (차이 없음)

REPLACE(str,findstr,replacestr)
SUBSTRING(str,start,len) : == MID?

SUBSTRING_INDEX(str,findstr,등장횟수) : str 안에서 선형탐색하다가 findstr이 등장횟수가 되면 중지함 (마지막 findstr은 포함되지 않음.)
ex. SUBSTRING_INDEX("aaa,bbb,ccc,ddd",',',2) : aaa,bbb

# 날짜 함수
INTERVAL은 YEAR,MONTH,DAY,HOUR,MINUTE,SECOND

ADDDATE('2010-01-01', INTERVAL 31 DAY); = DATE_ADD
SUBDATE() = DATE_SUB

CURDATE() : 날짜만
CURTIME() : 시각만
NOW() : 날짜와 시각 붙여서
SYSDATE() : 날짜와 시각 붙여서

YEAR(DATE)
MONTH, DAYOFMONTH (중요), HOUR, MINUTE, SECOND, MICROSECOND, DAYOFYEAR (1년중며칠)

MONTHNAME(DATE) : 영어 월 이름  
DAYNAME(DATE) : 영어 요일 이름

DAYOFWEEK(DATE) : 요일 숫자 (0이 월요일) -> ODBC 표준
WEEKDAY(DATE) : 요일 숫자 (1이 일요일)

DATE(DATE): 날짜 추출
TIME(DATE): 시각 추출

DATEDIFF(DATE1,DATE2) : DATE1-DATE2 >> FROM_DAYS(days)
TIMEDIFF(TIME1,TIME2) : TIME1-TIME2
TIMESTAMPDIFF(EXTRACT,DATE1,DATE2)

LAST_DAY(DATE): 해당 월의 마지막 날짜
TIME_TO_SEC(TIME): 시각을 초로 변환

☆ DATE_FORMAT(DATE, FORMATSTR)
%Y : year(4자리)
%y : year(2자리)
%M : MONTHNAME
%b : MONTHNAME(SHORT)
%W : DAYNAME
%a : DAYNAME (SHORT)
%T : hh:mm:SS
%m : month (두자리)
%c : month (한자리 가능)
%d : dayofmonth
%e : dayofmonth (한자리 가능)
%H : 24시간짜리 (두자리) HOUR
%I : 12시간짜리 HOUR
%i : 분 (두자리)
%S : 초 (두자리)
%r : hh:mm:ss AM/PM

CONVERT_TZ(DATE, TZ1, TZ2)

# 논리 함수
IF(cond, true, false)
IFNULL(checkTarget, ifNULL)

# 통계 함수
COUNT, AVG, SUM, MIN, MAX (column)

# REGEXP
REGEXP_REPLACE('1123abc516', '[0-9]', '');
REGEXP_REAPLCE('1123abc516', '[^a-zA-Z], '');
REGEXP_INSTR(str, regexp, startpos, occurrence)
REGEXP_SUBSTR(str, regexp, startpos, occurrence)

# Type Casting
CAST(변환대상 AS TYPE)
CONVERT(변환대상, TYPE)
```


# WITH 로 쿼리 저장

`WITH table_name as (SQL)`

`WITH table1 as (SQL), table2 as (SQL)`

# 순위 함수

`ntile(num) over (ORDER BY COL1)`

`ROW_NUMBER() over (ORDER BY COL1)`

# 재귀 `WITH`

```sql
WITH RECURSIVE dfs AS (
    SELECT ID, PARENT_ID, 1 AS GENERATION
    FROM ECOLI_DATA
    WHERE PARENT_ID IS NULL

    UNION ALL

    SELECT e.ID, e.PARENT_ID, (o.GENERATION + 1) AS GENERATION
    FROM ECOLI_DATA e
    JOIN dfs o ON e.PARENT_ID = o.ID
)
```

``` sql
with RECURSIVE ranges as (
    SELECT 0 AS HOUR
    
    UNION ALL
    
    SELECT (e.HOUR+1) as HOUR FROM ranges e WHERE e.HOUR+1 < 24
)
```

RECURSIVE 먼저 써야 작동한다. ㅂㅅ같은 문법

위 SELECT가 초기값이다. ROOT에서 DFS를 한다고 보면 된다.

# 개편한 날짜비교

`(YEAR(DATE), MONTH(DATE)) = (2023,05)`

튜플비교