--7. ����������� �������� �� ������� ���� "Men's Sports Shorts" 
--������ "XL" � ����� "Womens Mountain Shorts" ������ "M".
-- ������� ProductModel, Product


USE AdventureWorksLT2008
SELECT (mensSportsShorts.Profit *2 + 3*womensMountainShorts.Profit) as Profit 
FROM 
(SELECT DISTINCT  (SalesLT.Product.ListPrice - SalesLT.Product.StandardCost) as Profit
FROM SalesLT.Product, SalesLT.ProductModel
WHERE SalesLT.Product.ProductModelID = SalesLT.ProductModel.ProductModelID AND
	 (SalesLT.ProductModel.Name LIKE 'Men%s Sports Shorts'
	 AND 	SalesLT.Product.Size LIKE 'XL')) as mensSportsShorts,
(SELECT DISTINCT  (SalesLT.Product.ListPrice - SalesLT.Product.StandardCost) as Profit
FROM SalesLT.Product, SalesLT.ProductModel
WHERE SalesLT.Product.ProductModelID = SalesLT.ProductModel.ProductModelID AND
	 (SalesLT.ProductModel.Name LIKE 'Women%s Mountain Shorts'
	 AND 	SalesLT.Product.Size LIKE 'M')) as womensMountainShorts