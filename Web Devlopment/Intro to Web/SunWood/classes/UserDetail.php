<?php
  class UserDetail {
    private $_Username;
    private $_Password;
    private $_Created;
    
    public function __construct() { }

    public function __destruct(){
      $this->_Username = null;
      $this->_Password = null;
      $this->_Created = null;
    }      
           
    public function setUsername($username) { 
      if (!is_string($username) || strlen(chop($username)) == 0)
        throw new Exception('Illegal username');
      else
        $this->_Username = chop($username);
    }
    public function setPassword($password) { 
      if (!is_string($password) || strlen(chop($password)) == 0)
        throw new Exception('Illegal Password');
      else
        $this->_Password = chop($password);
    }

    public function setCreated($created) { 
      if (!is_string($created) || strlen(chop($created)) == 0){
        # no action
      } else {
        $this->_Created = chop($created);
      }
    }

		public function getUsername(){ return $this->_Username; }
		public function getPassword(){ return $this->_Password; }
		public function getCreated(){ return $this->_Created; }
           
    public function __toString() {
      $txt = "";
      $txt .= "Username: " . $this->_Username . "<br />";
      $txt .= "Password: " . $this->_Password . "<br />";
      $txt .= "Created: " . $this->_Created . "<br />";
	  $txt .= "===========================<br />";
      
      return $txt;
    }      
}        
?>