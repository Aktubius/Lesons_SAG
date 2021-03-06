--CREATE TABLE ValueTable ([value] int)
GO

DECLARE @TransactionName varchar(20) 
SET @TransactionName = 'Transaction1';

--These statements start a named transaction,
--insert a two records, and then roll back
--the transaction named in the variable 
--@TransactionName.
--
--
--INSERT INTO ValueTable VALUES(1)
--INSERT INTO ValueTable VALUES(2)
--
--COMMIT TRANSACTION @TransactionName
--
--INSERT INTO ValueTable VALUES(3)
--INSERT INTO ValueTable VALUES(4)
--
--SELECT * FROM ValueTable

--DROP TABLE ValueTable

DECLARE @ErrorHappened bit
SET @ErrorHappened = 0

BEGIN TRANSACTION @TransactionName

BEGIN TRY
   INSERT INTO ValueTable VALUES(1)
   INSERT INTO ValueTable VALUES(2)

   --SELECT 1 / 0;
END TRY
BEGIN CATCH
    ROLLBACK TRANSACTION @TransactionName
END CATCH;

IF(@ErrorHappened <> 0)
	COMMIT TRANSACTION @TransactionName

SELECT * FROM ValueTable