    <?php include("includes/header.php"); ?>
<?php include("includes/navigation.php"); ?>
<!-- start main content area -->
<section>

<form method="post" name="formReservation" id="formReservation" action="Confirmation.php">
<h4>Required fields are marked with an asterisk *</h4>

<table>

<tr>
    <td class="lbl"><label id="lblFirstName">First Name <span class="star">*</span>:</label></td>
    <td>
    <input id="FirstName" name="FirstName" type="text" required="required" placeholder="First Name" autofocus="autofocus" /> <br />
    </td>
</tr>

<tr>
    <td class="lbl"><label id="lblLastName">Last Name <span class="star">*</span>:</label></td>
    <td>
    <input id="LastName" name="LastName" type="text" required="required" placeholder="Last Name" />
    </td>
</tr>

<tr>
    <td class="lbl"><label id="lblArrivalDate">Arrival Date <span class="star">*</span>:</label></td>
    <td>
    <input id="ArrivalDate" name="ArrivalDate" type="date" required="required"></td>
</tr>

<tr>
    <td class="lbl"><label id="lblPersons">Number of Persons <span class="star">*</span>:</label></td>
    <td>
    <input id="Persons" name="Persons" type="range" min="1" max="10" />
    <span id="personsValue">&nbsp;&nbsp;</span></td>
</tr>

<tr>
    <td class="lbl"><label id="lblNights">Number of Nights <span class="star">*</span>:</label></td>
    <td>
    <input id="Nights" name="Nights" type="number" min="0" max="14" step="7"  required="required" /></td>
</tr>

<tr>
    <td class="lbl"><label id="lblFirstName1">E-mail <span class="star">*</span>:</label></td>
    <td><input id="Email" name="Email" type="email" required="required" /></td>
</tr>

<tr>
    <td class="lbl"><label id="lblFirstName2">Phone <span class="star">*</span>:</label></td>
    <td><input id="Phone" name="Phone" type="text"  required="required" /></td>
</tr>

<tr>
<td class="lbl"><label id="lblArrivingBy">Arriving by <span class="star">*</span>:</label></td>
<td>
    <input id="car" type="radio" value="Car" name="ArrivingBy" checked="checked"/>
    <label for="car">Car</label>
    &nbsp;&nbsp;
    <input id="boat" type="radio" value="Boat" name="ArrivingBy"/>
    <label for="boat" >Boat</label>
    &nbsp;&nbsp;
    <input id="air" type="radio" value="Air" name="ArrivingBy"/>
    <label for="air" >Air</label>
    &nbsp;&nbsp;
    <input id="other" type="radio" value="Other" name="ArrivingBy"/>
    <label for="other" >Other</label>
</td>
</tr>

<tr>
<td class="lbl"><label id="lblFacility">Facility Requested <span class="star">*</span>:</label></td>
<td>
    <select name="Facility" size="4"  required="required"> 
        <option value="Room" selected="selected">Room</option>
        <option value="Suite">Suite</option>
        <option value="Meeting Room">Meeting Room</option>
        <option value="Grand Ballroom">Grand Ballroom</option>
        <option value="Other">Other (details in comments field)</option>
    </select>
</td>
</tr>

<tr>
    <td class="lbl"><label id="lblFirstName3">Comments:</label></td>
    <td><textarea id="Comments" name="Comments" rows="6"></textarea></td>
</tr>

<!--Submit buttons-->
<tr>
<td>&nbsp;</td>
<td class="buttons">
    <input type="reset" value="Cancel" />&nbsp;&nbsp;&nbsp;&nbsp;
    <input name="submit" type="submit" value="Submit" id="btn" />
</td>
</tr>

</table>
</form>
</section>
<!-- end main content area -->
<?php include("includes/footer.php"); ?>
<!-- end footer -->