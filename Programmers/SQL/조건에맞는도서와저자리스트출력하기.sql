SELECT a.book_id, b.author_name, DATE_FORMAT(a.published_date,'%Y-%m-%d') as published_date
from book as a
join author as b
on a.author_id = b.author_id
where a.category = '경제'
order by published_date 