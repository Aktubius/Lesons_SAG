set ANSI_NULLS ON
set QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
ALTER TRIGGER [SalesLT].[CustomerInsteadOfDelete]
   ON  [SalesLT].[Customer]
   INSTEAD OF DELETE
AS 
BEGIN
	DECLARE @DeletingCustomerID INT
	SET 
	@DeletingCustomerID = (SELECT TOP 1 CustomerID FROM Deleted)
	

	UPDATE [AdventureWorksLT].[SalesLT].[Customer]
	SET 
		IsDeleted = 1,
		ModifiedDate = GETDATE()
	WHERE [AdventureWorksLT].[SalesLT].[Customer].[CustomerID] = @DeletingCustomerID
END
