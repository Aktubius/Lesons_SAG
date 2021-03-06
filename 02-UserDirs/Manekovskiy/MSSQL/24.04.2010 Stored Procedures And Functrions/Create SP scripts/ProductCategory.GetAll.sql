USE [AdventureWorksLT]
GO
/****** Object:  StoredProcedure [dbo].[ProductCategory.GetAll]    Script Date: 04/24/2010 13:53:08 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[ProductCategory.GetAll]
	@ProductCategoryName nvarchar(50) = NULL,
	@ParentProductCategoryName nvarchar(50) = NULL
AS
BEGIN
	SELECT 
		Category.[ParentProductCategoryID], 
		Category.[ProductCategoryID], 
		Category.[Name]
	FROM SalesLT.ProductCategory AS Category
	INNER JOIN SalesLT.ProductCategory AS BaseCategory 
		ON BaseCategory.ProductCategoryID = Category.ParentProductCategoryID
	WHERE 
		BaseCategory.[Name] LIKE '%' + @ParentProductCategoryName + '%' AND
		Category.[Name] LIKE '%' + @ProductCategoryName + '%'
END