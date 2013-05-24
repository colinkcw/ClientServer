<?php include("includes/header.php"); ?>
<?php include("includes/navigation.php"); ?>

<?php 
require_once("classes/UserDetail.php");
require_once("classes/User.php");
?>
    
<!-- start main content area -->
<section>
<table>

<!--Headings-->
<tr>
    <td><b>Username</b></td>
    <td><b>Password</b></td>
    <td><b>Created</b></td>
</tr>

<?php
    $allusers = new User();
    foreach ($allusers->getUsers() as $row) {
    echo "<tr>";
    echo "<td>" . $row->getUsername() . "</td>";
    echo "<td>" . $row->getPassword() . "</td>";
    echo "<td>" . $row->getCreated() . "</td>";
    echo "</tr>";
    }
?>
</table>
</section>
<!-- end main content area -->
<?php include("includes/footer.php"); ?>
<!-- end footer -->