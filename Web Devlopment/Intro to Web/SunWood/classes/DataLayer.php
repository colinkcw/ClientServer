<?php
class DataLayer {
  private $_connection;

  const HOSTNAME = "mysql.vncvr.ca";
  const DATABASE = "sunwood";
  const USERNAME = "sunuser";
  const PASSWORD = 'sunpass';

  public function __construct() {
  }

  public function getConnection(){ 
    $connection = mysql_connect(self::HOSTNAME, self::USERNAME, self::PASSWORD);
    $db = self::DATABASE;
    mysql_select_db($db, $connection) or die( "Could not open $db"); 

    return $connection;
  }
}
?>