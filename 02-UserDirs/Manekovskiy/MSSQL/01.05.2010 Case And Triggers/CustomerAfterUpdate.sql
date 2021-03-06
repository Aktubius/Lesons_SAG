set ANSI_NULLS ON
set QUOTED_IDENTIFIER ON
GO
ALTER TRIGGER [SalesLT].[CustomerAfterUpdate]
   ON  [SalesLT].[Customer]
   AFTER UPDATE
AS 
BEGIN
	UPDATE [SalesLT].[Customer]
	SET [ModifiedDate] = GETDATE() 
	WHERE [SalesLT].[Customer].[CustomerID] = (SELECT TOP 1 CustomerID FROM INSERTED)
END

