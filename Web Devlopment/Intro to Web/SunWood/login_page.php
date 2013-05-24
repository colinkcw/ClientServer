<?php 
    include("includes/header.php");
    include("includes/navigation.php");
    require_once("classes/UserDetail.php");
    require_once("classes/User.php");
   
    if (isset($_SESSION['authenticate'])) {
        header("Location:reports.php");
    }
?>

<!-- start main content area -->
<section>
<form method="post" name="userLogin" id="userLogin" action="login_page.php">

<table>

<tr>
    <td>
        <label name="lblUserName" id="lblUserName"><b>User Name</b></label>
        <input name="userName" type="text" id="userName" 
        placeholder="adam@adam.com" autofocus="autofocus"/> <br/>
    </td>
</tr>

<tr>
    <td>
        <label name="lblPassword" id="lblPassword"><b>Password</b></label>
        <input name="password" id="password" type="password"
        placeholder="adam"/>
    </td>
</tr>

<tr>
    <td>
    <input type="submit" name="submitButton" id="submitButton" value="Submit"/>
    </td>
</tr>

</table>
</form>

<?php
    extract($_POST);
    if((isset($_POST['userName'])) && (isset($_POST['password']))) {  
        $u = new User();
        if ($u->authenticateUser($_POST['userName'], $_POST['password'])) {
           $_SESSION['authenticate'] = true;
           header("Location:reports.php");
        } else {
            echo "<p style=\"color:red\">That username & password combo is not in our database</p>";
            echo "</br>";
        }
    }
?>

</section>
<!-- end main content area -->

<?php include("includes/footer.php"); ?>
<!-- end footer -->