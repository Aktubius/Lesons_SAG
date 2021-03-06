USE [AdventureWorksLT]
GO
/****** Object:  StoredProcedure [dbo].[ProductCategory.Delete]    Script Date: 04/24/2010 13:52:28 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[ProductCategory.Delete]
	@ProductCategoryID int = NULL,
	@AffectedRows int = 0 OUTPUT
AS
BEGIN
	DELETE FROM [SalesLT].[ProductCategory]
	WHERE [SalesLT].[ProductCategory].[ProductCategoryID] = @ProductCategoryID
	
	RETURN @@ROWCOUNT;
END