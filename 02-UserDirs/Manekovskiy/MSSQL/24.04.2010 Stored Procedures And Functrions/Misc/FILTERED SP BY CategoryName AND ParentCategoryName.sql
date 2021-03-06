ALTER PROCEDURE [dbo].[CategoryGetAll]
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

---

DECLARE @RC int
DECLARE @ParentProductCategoryName nvarchar(50)
SET @ParentProductCategoryName = 'Comp'

DECLARE @ProductCategoryName nvarchar(50)
SET @ProductCategoryName = 'B'

-- TODO: Set parameter values here.

EXECUTE @RC = [AdventureWorksLT].[dbo].[CategoryGetAll] 
   @ProductCategoryName
  ,@ParentProductCategoryName
