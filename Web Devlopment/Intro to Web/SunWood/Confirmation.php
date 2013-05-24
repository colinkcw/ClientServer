<?php 
include("includes/header.php");
include("includes/navigation.php"); 
require_once("classes/Reservation.php");
require_once("classes/ReservationDetail.php");
?>

<!--Confirmation.php: This php file validates the data that is being passed by 
    'reservations.php' and posts it on to the database --> 

<!-- start main content area -->
<section>
<?php

extract($_POST);
$reservationDetail = new ReservationDetail();
$thankYouMessage ="<h1>Thank you, your reservation has been received.</h1>";
$badDataMessage = "";

//Validate all required fields and set them to ReservationDetail class variables
if ($FirstName == null) {
    $badDataMessage .= "You did not enter your first name" . "</br>";
} else if (!preg_match("/^[A-Za-z]+$/",$FirstName)) {
    $badDataMessage .= "Your first name must only contain letters" . "</br>";
} else {
    $reservationDetail->setFirstName($FirstName);
}

if ($LastName== null) {
    $badDataMessage .= "You did not enter your last name" . "</br>";
} else if (!preg_match("/^[A-Za-z]+$/",$LastName)) {
    $badDataMessage .= "Your last name must only contain letters" . "</br>";
} else {
    $reservationDetail->setLastName($LastName);
}

if ($ArrivalDate == null) {
    $badDataMessage .= "You did not enter an arrival date" . "</br>";
} else if (!preg_match("/^\d{4}\-\d{1,2}\-\d{1,2}$/",$ArrivalDate)) {
    $badDataMessage .= "Enter your arrival date in an appropriate format: yyyy-mm-dd" . "</br>";
} else {
    $reservationDetail->setArrivalDate($ArrivalDate);
}

if ($Persons == null) {
    $badDataMessage .= "You did not enter the number of people coming" . "</br>";
} else if (!preg_match("/^[\d]{1,2}$/",$Persons)) {
    $badDataMessage .= "Number of people cannot exceed 2 digits" . "</br>";
} else {
    $reservationDetail->setNumberOfPersons($Persons);
}

if ($Nights == null) {
    $badDataMessage .= "You did not enter the number of nights you are staying" . "</br>";
} else if (!preg_match("/^0$|^7$|^14$/",$Nights)) {
    $badDataMessage .= "Valid number of nights are only 0, 7, or 14" . "</br>";
} else {
    $reservationDetail->setNumberOfNights($Nights);
}

if ($Email == null) {
    $badDataMessage .= "You did not enter your email" . "</br>";
} else if (!preg_match("/^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,4})$/", $Email)){
    $badDataMessage .= "Please enter your email in a proper format: user@domain.com" . "</br>";
} else {
    $reservationDetail->setEmail($Email);
}

if ($Phone == null) {
    $badDataMessage .= "You did not enter your phone number" . "</br>";
} else if (!preg_match("/\d{3}\-\d{3}\-\d{4}/", $Phone)){
    $badDataMessage .= "Please enter your phone number in a correct format: 999-999-9999" . "</br>";
} else {
    $reservationDetail->setPhone($Phone);
}

if ($ArrivingBy == null) {
    $badDataMessage .= "You must choose at least one method of arrival" . "</br>";
} else {
    $reservationDetail->setArrivingBy($ArrivingBy);
}

if ($Facility != null) {
    $reservationDetail->setFacilityRequested($Facility);
} else {
    $badDataMessage .= "You did not specify what kind of facility you're requesting" . "</br>";
}

if ($Comments != null) {
    $reservationDetail->setComments($Comments);
} else if (($Facility == "Other") && ($Comments == null)) {
    $badDataMessage .= "You must specify an alternative facility in the comments section" . "</br>";
}

//If data is all valid. Post data on to the database
if (strlen($badDataMessage) == 0) {
    echo $thankYouMessage;
    $reservation = new Reservation();
    $reservation->insert($reservationDetail);
} else {
    echo "<span style=color:red>" . $badDataMessage . "</span> </br>
    <h1>Please hit the back button and re-enter the required values</h1>" ;
}
?>
</section>
<!--end main content area-->
<?php include("includes/footer.php");?>
<!--end footer-->