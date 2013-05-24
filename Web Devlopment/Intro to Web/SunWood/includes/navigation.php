<?php session_start(); ?>
<nav id="nav">
	<ul>
		<li><a href="index.php">Home</a></li>
		<li><a href="reservations.php">Reservation</a></li>
		<li><a href="login_page.php">Reports</a></li>
        <?php	
        if (isset($_SESSION['authenticate'])) {
                echo "<li>";
                echo "<a href=\"logout_page.php\">Logout</a>";
                echo "</li>";
        }
        ?>
	</ul>
</nav>