set nocount on
use Book
if Exists(select name from sysobjects where NAME = 'avg_price' and type='P')
drop procedure avg_price
go
create procedure avg_price @price int output
as 
set @price=
(select AVG(bookprice) as ƽ���۸�
from book)
print @price 

exec avg_price 1


--�� pubs ���ݿ��д����洢���� max_price������ָ����ͼ�����ͣ�������������ظ���ͼ�����ߵ��ۣ������������Ҫ���ڴ����洢����ǰҪ���жϸô洢�����Ƿ��Ѵ��ڣ�������ڣ�����ɾ����
use Book
go
if Exists(select name from sysobjects where NAME = 'max_price' and type='P')
drop procedure max_price
go
create procedure max_price @bookname varchar(10) output
as
select MAX(bookprice)as ��߼۸�
from book
group by bookname



exec  max_price 'web' 
print @bookname
drop procedure avg_price,max_price

drop procedure  info

--�޷��������ݿ��û�
--���ݿ�����-��ȫ��-�û�-�Ҽ�

--1.1����������ͼ�顱�۸����10%
select price=price*1.1
from class,book
where book.classNO=class.classNo and classname='������'

--1.2�������������ͼ�鵥���µ�10%
select price=price*0.9
from book
where shopNum=MAX(shopNum)

--1.3ɾ�����ߡ���С�ꡱ�Ľ����¼
delete from returnbook
where readerNO in
(select readerNo
from book
where readername='��С��')


--1.4����һ����ͼ������ͼΪ�ڽ�����ܼ�60Ԫ���ϵĶ��߱�š�����������ͼ����ܼ�
IF EXISTS(SELECT 1 FROM sys.views WHERE name='price_over_60')
drop view price_over_60
go
CREATE VIEW price_over_60
WITH SCHEMABINDING,VIEW_METADATA
AS
SELECT reader.readerNo,readername,sum(price)
FROM reader,returnbook,
where reader.readerNo=returnbook.readerNo
group by readerNo
having sum(price)>=60
WITH CHECK OPTION

--1.5����һ����ͼ������ͼΪ������25-35��֮��Ķ��������а������߱�š����������䡢������λ����ͼ�����ƺͽ������ڡ�

IF EXISTS(SELECT 1 FROM sys.views WHERE name='age_between_25_35')
drop view age_between_25_35
go
create view age_between_25_35
WITH SCHEMABINDING,VIEW_METADATA
as
declare @age int
select reader.readerNo as ���,readername as ����,workUnit as ������λ��@age=(DateName(year,GetDate())-cast(SUBSTRING('identifycard',7,4))as int)as ����,bookname as �����ͼ������,borrowDate as ��������
from reader, returnbook
where reader.readerNo=returnbook.readerNo and (@age between 25 and 35)
WITH CHECK OPTION

declare @time int
select @time=DateName(year,GetDate())
print @time


dbcc checkalloc('Book')
                                         