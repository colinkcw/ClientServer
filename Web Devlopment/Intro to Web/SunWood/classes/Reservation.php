<?php
	require_once("ReservationDetail.php");
	require_once("DataLayer.php");

class Reservation extends ReservationDetail {
    public function __construct() { }
    public function __destruct() { }

    public function getReservationById($id) {

      $sql = "SELECT * FROM reservations WHERE ReservationId = " . $id;

	  $result = $this->getResult($sql);
      $row = mysql_fetch_array($result);
	  
      if (count($row) > 1)
		return $this->getDetailFromDbRow($row);
      else
		return null;
    }
	
    public function getReservationByName($firstName, $lastName) {
      $sql = "SELECT * FROM Reservations WHERE FirstName = '" . chop($firstName) . "'" . " AND LastName = '" . chop($lastName) . "'";

	  $result = $this->getResult($sql);
      $row = mysql_fetch_array($result);
      
      if (count($row) > 1)
		return $this->getDetailFromDbRow($row);
      else
		return null;
    }

    public function getReservations() {
      $sql = "SELECT * FROM Reservations";

	  $result = $this->getResult($sql);
      $num_result = mysql_num_rows($result);

      for ($i=0; $i < $num_result; $i++) {
        $row = mysql_fetch_array($result);

        if (count($row) > 1)
          $all[] = $this->getDetailFromDbRow($row);
      }
      return $all;
    }

    public function getReservationsByKeyword($keyword) {
      $sql = "SELECT * FROM Reservations";
      $sql .= " WHERE FirstName LIKE '%$keyword%'";
      $sql .= " OR LastName LIKE '%$keyword%'";
      $sql .= " OR Email LIKE '%$keyword%'";
      $sql .= " OR Phone LIKE '%$keyword%'";
      $sql .= " OR ArrivingBy LIKE '%$keyword%'";
      $sql .= " OR FacilityRequested LIKE '%$keyword%'";
      $sql .= " OR Comments LIKE '%$keyword%'";

	  $result = $this->getResult($sql);

      $num_result = mysql_num_rows($result);

      for ($i=0; $i < $num_result; $i++) {
        $row = mysql_fetch_array($result);

        if (count($row) > 1)
          $all[] = $this->getDetailFromDbRow($row);
      }
      return $all;
    }

    public function deleteBlank() {
      $dataLayer = new DataLayer(); 
      $connection = $dataLayer->getConnection();

      $sql = "DELETE FROM Reservations WHERE ";
	  $sql .= " FirstName = ''";
	  $sql .= " OR LastName = ''";
	  $sql .= " OR ArrivalDate = ''";
	  $sql .= " OR Email = ''";
	  $sql .= " OR Phone = ''";
	  $sql .= " OR ArrivingBy = ''";
	  $sql .= " OR FacilityRequested = ''";

	  $res = mysql_query($sql, $connection) or die( "Could not execut sql: $appid:  $sql");

      if ( !$res )
        return false;
      else
        return true;
    }

    public function getResult($sql) {
      $dataLayer = new DataLayer(); 
      $connection = $dataLayer->getConnection();

      $result = mysql_query($sql, $connection) or die( "Could not execut sql: $sql");

      if ($result == false)    {        
        error_log("SQL error: ".mysql_error()."\n\nOriginal query: $sql\n"); 
        // Remove following line from production servers         
        //die("SQL error: ".mysql_error()."\b<br>\n<br>Original query: $string \n<br>\n<br>");    
      }    
      return $result;    
    }

    public function delete($id) {
	
		if ($this->getReservationById($id) == null)
			return false;
		

		$dataLayer = new DataLayer(); 
		$connection = $dataLayer->getConnection();

		$sql = "DELETE FROM Reservations WHERE ReservationId = $id ";

		$res = mysql_query($sql, $connection) or die( "Could not execut sql: $appid:  $sql");

		if ( !$res )
			return false;
		else
			return true;
    }

    public function update($recordDetail) {
      $dataLayer = new DataLayer(); 
      $connection = $dataLayer->getConnection();

      $id = $recordDetail->getReservationId();

	  //echo $recordDetail;
	  //die;

      $sql = " UPDATE Reservations";
      $sql .= " SET ";
      $sql .= " FirstName = '" . $recordDetail->getFirstName() . "',";
      $sql .= " LastName = '" . $recordDetail->getLastName() . "',";
      $sql .= " ArrivalDate = '" . $recordDetail->getArrivalDate() . "',";
      $sql .= " NumberOfPersons = '" . $recordDetail->getNumberOfPersons() . "',";
      $sql .= " NumberOfNights = '" . $recordDetail->getNumberOfNights() . "',";
      $sql .= " Email = '" . $recordDetail->getEmail() . "',";
      $sql .= " Phone = '" . $recordDetail->getPhone() . "',";
      $sql .= " ArrivingBy = '" . $recordDetail->getArrivingBy() . "',";
      $sql .= " FacilityRequested = '" . $recordDetail->getFacilityRequested() . "',";
      $sql .= " Comments = '" . $recordDetail->getComments() . "' ";

      $sql .= " WHERE ReservationId = $id;";

      $res = mysql_query($sql, $connection) or die( "Could not execut sql: $id:  $sql");

      if ( !$res )
        return false;
      else
        return true;
    }

    public function insert($recordDetail) {
      $dataLayer = new DataLayer(); 
      $connection = $dataLayer->getConnection();

	  $nextid = $this->getNextId();

      $sql = "INSERT INTO Reservations (";
      $sql .= "ReservationId,";
      $sql .= "FirstName, ";
      $sql .= "LastName, ";
      $sql .= "ArrivalDate, ";
      $sql .= "NumberOfPersons, ";
      $sql .= "NumberOfNights, ";
      $sql .= "Email, ";
      $sql .= "Phone, ";
      $sql .= "ArrivingBy, ";
      $sql .= "FacilityRequested, ";
      $sql .= "Comments ";
      $sql .= ") VALUES (";
      $sql .= "'$nextid',";
      $sql .= "'" . $recordDetail->getFirstName() . "',";
      $sql .= "'" . $recordDetail->getLastName() . "',";
      $sql .= "'" . $recordDetail->getArrivalDate() . "',";
      $sql .= "'" . $recordDetail->getNumberOfPersons() . "',";
      $sql .= "'" . $recordDetail->getNumberOfNights() . "',";
      $sql .= "'" . $recordDetail->getEmail() . "',";
      $sql .= "'" . $recordDetail->getPhone() . "',";
      $sql .= "'" . $recordDetail->getArrivingBy() . "',";
      $sql .= "'" . $recordDetail->getFacilityRequested() . "',";
      $sql .= "'" . $recordDetail->getComments() . "' ";
      $sql .= ")";

      $res = mysql_query($sql, $connection) or die( "Could not execut sql: $nextid:  $sql");

      if ( !$res ) {
        return false;
      } else {
        return true;
      }
    }

    public function getNextId() {
      $dataLayer = new DataLayer(); 
      $connection = $dataLayer->getConnection();

      $sql = "SELECT Max(ReservationId) AS currentid FROM Reservations";

      $result = mysql_query($sql, $connection) or die( "Could not execute sql: $sql");

      $row = mysql_fetch_array($result);
      $nextid = $row["currentid"] ;
      $nextid++;

      settype($nextid,"string");

      return $nextid;
    }
	
	private function getDetailFromDbRow($row) {
		$record = new ReservationDetail();

        $record->setReservationId($row["ReservationId"]);
        $record->setFirstName($row["FirstName"]);
        $record->setLastName($row["LastName"]);
        $record->setArrivalDate($row["ArrivalDate"]);
        $record->setNumberOfPersons($row["NumberOfPersons"]);
        $record->setNumberOfNights($row["NumberOfNights"]);
        $record->setEmail($row["Email"]);
        $record->setPhone($row["Phone"]);
        $record->setArrivingBy($row["ArrivingBy"]);
        $record->setFacilityRequested($row["FacilityRequested"]);
        $record->setComments($row["Comments"]);
        $record->setCreated($row["Created"]);
		
		return $record;
	}
}
?>