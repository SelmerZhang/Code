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

select COUNT(bookname)
from book
where bookid<10
group by all bookname
--����all��id����10����Ϣ��Ȼ����ͳ�ƣ�����ȴ����ʾ��������¼

use Book
select bookname,�۸�=case
when bookprice>0 and bookprice<30 then '����'
when bookprice>30 and bookprice<60 then 'һ��'
else '��'
end
from book


select *
from book 
order by bookname
compute avg(bookprice)by bookname



