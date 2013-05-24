<?php
require_once("UserDetail.php");
require_once("DataLayer.php");

  class User extends UserDetail {
    public function __construct() { }
    public function __destruct() { }
    
    public function authenticateUser($username, $password) {
      $usr = $this->getUserByCredentials(chop($username), chop($password));
      if ($usr != null && chop($usr->getUserName()) == chop($username))
        return true;
      else
        return false;
    }

    public function getUserByCredentials($username, $password) {
      $dataLayer = new DataLayer(); 
      $connection = $dataLayer->getConnection();

      $sql = " SELECT * FROM SunwoodUsers";
      $sql .= " WHERE uid='" . $username . "' and  pwd='" . $password . "'";

      $result = mysql_query($sql, $connection) or die( "Could not execut sql: $sql");
      $row = mysql_fetch_array($result);
            
      if (count($row) > 1) {
		return $this->getDetailFromDbRow($row);
      } else
		return null;
    }

    public function getUserByUsername($username) {
      $dataLayer = new DataLayer(); 
      $connection = $dataLayer->getConnection();

      $sql = " SELECT * FROM SunwoodUsers";
      $sql .= " WHERE uid='" . $username . "'";

      $result = mysql_query($sql, $connection) or die( "Could not execut sql: $sql");
      $row = mysql_fetch_array($result);
      
      if (count($row) > 1) {
		return $this->getDetailFromDbRow($row);
      } else
		return null;
    }

    public function getUsers() {
      $dataLayer = new DataLayer(); 
      $connection = $dataLayer->getConnection();

      $sql = "SELECT * FROM SunwoodUsers";

      $result = mysql_query($sql, $connection) or die( "Could not execut sql: $sql");

      $num_result = mysql_num_rows($result);

      for ($i=0; $i < $num_result; $i++) {
        $row = mysql_fetch_array($result);

        if (count($row) > 1)
          $all[] = $this->getDetailFromDbRow($row);
      }
      return $all;
    }

    public function delete($uid) {
      $dataLayer = new DataLayer(); 
      $connection = $dataLayer->getConnection();

		if ($this->getUserByUsername($uid) == null)
			return false;


      $sql = "DELETE FROM SunwoodUsers WHERE uid = '" . $uid . "'";

      $res = mysql_query($sql, $connection) or die( "Could not execut sql: $uid - $sql");

      if ( !$res )
        return false;
      else
        return true;
    }

    public function update($usrDetail) {
      $dataLayer = new DataLayer(); 
      $connection = $dataLayer->getConnection();

      $id = $usrDetail->getUsername();

      $sql = " UPDATE SunwoodUsers";
      $sql .= " SET ";
      $sql .= " uid = '" . $usrDetail->getUsername() . "',";
      $sql .= " pwd = '" . $usrDetail->getPassword() . "' ";
      $sql .= " WHERE uid = '" . $id . "'";

      $res = mysql_query($sql, $connection) or die( "Could not execut sql: $id:  $sql");

      if ( !$res )
        return false;
      else
        return true;
    }

    public function insert($usrDetail) {
		if ($this->getUserByUsername($usrDetail->getUsername()) != null) {
			$uid = $usrDetail->getUsername();
			die( "Username [$uid] already exists in the database");
		}
	
      $dataLayer = new DataLayer(); 
      $connection = $dataLayer->getConnection();

      $sql = "INSERT INTO SunwoodUsers (";
      $sql .= "uid,";
      $sql .= "pwd  ";
      $sql .= ") VALUES (";
      $sql .= "'" . $usrDetail->getUsername() . "',";
      $sql .= "'" . $usrDetail->getPassword() . "' ";
      $sql .= ")";

      $res = mysql_query($sql, $connection) or die( "Could not execut sql: $sql");

      if ( !$res ) {
        return false;
      } else {
        return true;
      }
    }

	private function getDetailFromDbRow($row) {
		$record = new UserDetail();

        $record->setUsername($row["uid"]);
        $record->setPassword($row["pwd"]);
        $record->setCreated($row["created"]);
		
		return $record;
	}
}
?>