-- ================================================
-- Template generated from Template Explorer using:
-- Create Trigger (New Menu).SQL
--
-- Use the Specify Values for Template Parameters 
-- command (Ctrl-Shift-M) to fill in the parameter 
-- values below.
--
-- See additional Create Trigger templates for more
-- examples of different Trigger statements.
--
-- This block of comments will not be included in
-- the definition of the function.
-- ================================================
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
CREATE TRIGGER dbo.DeleteEmployee
   ON  dbo.employee
   FOR UPDATE
AS 
BEGIN
DECLARE @oldSalary int,
		@newSalary int,
		@id	int,
		@hiID int;
SELECT	@oldSalary = newSalary from empHist;
SELECT	@newSalary = i.salary from inserted i;
SELECT	@hiID = id from empHist;
SELECT  @id = i.id from inserted i;
update empHist set oldSalary = @oldSalary  where @hiID = @id;
update empHist set newSalary = 0 where @hiID = @id;  
END
GO
