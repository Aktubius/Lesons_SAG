USE [AdventureWorksLT]
GO
/****** Object:  StoredProcedure [dbo].[ProductCategory.Insert]    Script Date: 04/24/2010 13:53:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		Manekovskiy Alexander
-- Create date: 04/24/2010
-- Description:	Insert SP for Category table
-- =============================================
CREATE PROCEDURE [dbo].[ProductCategory.Insert]
	@ParentProductCategoryID int = NULL,
	@Name varchar(50) = null,
	@rowguid uniqueidentifier = null,
	@ModifiedDate datetime = null,

	@InsertedID int OUTPUT
AS
BEGIN
	INSERT INTO [SalesLT].[ProductCategory](
		[ParentProductCategoryID],
		[Name],
		[rowguid],
		[ModifiedDate])
	VALUES(
		@ParentProductCategoryID,
		@Name,
		@rowguid,
		@ModifiedDate
	);

 RETURN @@IDENTITY;
END