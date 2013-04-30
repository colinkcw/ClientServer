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
CREATE TRIGGER dbo.InsertEmployee
   ON  dbo.employee
   AFTER Insert
AS 
BEGIN
DECLARE @newId int,
		@newSalary int
SELECT	@newId = i.id from inserted i;
SELECT	@newSalary = i.salary from inserted i;
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	Insert into dbo.empHist Values(@newId,0,@newSalary,SYSDATETIME());

    -- Insert statements for trigger here

END
GO
