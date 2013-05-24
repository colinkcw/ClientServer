<?php
include("includes/header.php");
require_once("classes/Reservation.php");
require_once("classes/ReservationDetail.php");
?>

<!-- start main content area -->
<section class="blah" >
<div class="navi1">
<?php include("includes/navigation.php"); ?>
</div>
 <h2>Reservation Report</h2> 
 <form name="search" method="post" action="report_reservations.php">
 Seach for: <input type="text" name="find" >  
 <input type="submit" name="search" value="Search" >
 </form>

<table border="1" bordercolor="black">

<tr>
	<td><b>First Name</b></td>
	<td><b>Last Name</b></td>
	<td><b>Arrival Date</b></td>
	<td><b>Persons</b></td>
	<td><b>Nights</b></td>
	<td align='center'><b>Email</b></td>
	<td align='center'><b>Phone</b></td>
	<td><b>Arr. By</b></td>
	<td align='center'><b>Facility</b></td>
	<td><b>Delete</b></td>
</tr>

<?php


$reservation = new Reservation();
$all = $reservation->getReservations();
if (isset($_POST['find'])){
$all = $reservation->getReservationsByKeyword($_POST['find']);
displayvalues($all);
}

if(isset($_GET['id'])) {
$reservation->delete($_GET['id']);
$all =  $reservation->getReservations();
//displayvalues($all); 
}
$all = $reservation->getReservations();
displayvalues($all);


/*function deleteReservation($id, $reservation) {
	$reservation->delete($id);
}*/

function displayvalues($all){ $i = 0;
foreach ($all as $row) {


	$id = $row->getReservationId();
	echo "<tr title=\" " . $row->getComments() . "\">";
	echo "<td>" . $row->getFirstName() . "</td>";
	echo "<td>" . $row->getLastName() . "</td>";
	echo "<td>" . $row->getArrivalDate() . "</td>";
	echo "<td>" . $row->getNumberOfPersons()."</td>";
	echo "<td>" . $row->getNumberOfNights() . "</td>";
	echo "<td>" . $row->getEmail() . "</td>";
	echo "<td>" . $row->getPhone() . "</td>";
	echo "<td>" . $row->getArrivingBy() . "</td>";
	echo "<td>" . $row->getFacilityRequested() . "</td>";
	echo"<td><a href='report_reservations.php?id=".$id ."'><img src='images/delete.gif' alt='Delete' border='0'></a></td>";
	echo"</tr>";
	$i++;
}
echo "<tr>";
echo"<td colspan='9' align='center'>Total</td>";
echo"<td align='center'>".$i."</td>";
echo "</tr>";

}
?>

</table>
<div class="navi1">
<?php include("includes/footer.php"); ?>
</div>

<!-- 
end main content area -->
</section>


<!-- end footer -->
