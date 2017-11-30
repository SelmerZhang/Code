use Book 
;with name as
(select bookname
from book 
where bookid<9
)
select bookname,avg(bookprice)
from book
where bookname in (select * from name)
group by bookname

with expression
select column_list
from table_name1,table_name2
where expression
group by column_name
having expression
order by column_name

use Book
select * into hightbookprice
from book
where bookprice>50




