--11. �� ��������, ������� ������� ���� � 
--����������� ����� ���� �������(SalesOrderDetail.OrderQty)
USE AdventureWorksLT2008
SELECT SalesLT.Product.Name
FROM SalesLT.Product
WHERE 5<( SELECT AVG (SalesLT.SalesOrderDetail.ProductID)
		  FROM SalesLT.SalesOrderDetail
)