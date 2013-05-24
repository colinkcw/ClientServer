<?php
class ReservationDetail {
    private $_ReservationId;
    private $_FirstName;
    private $_LastName;
    private $_ArrivalDate;
    private $_NumberOfPersons;
    private $_NumberOfNights;
    private $_Email;
    private $_Phone;
    private $_ArrivingBy;
    private $_FacilityRequested;
    private $_Comments;
    private $_Created;
    
    public function __construct() { }

    public function __destruct(){
      $this->_ReservationId = null;
      $this->_FirstName = null;
      $this->_LastName = null;
      $this->_ArrivalDate = null;
      $this->_NumberOfPersons = null;
      $this->_NumberOfNights = null;
      $this->_Email = null;
      $this->_Phone = null;
      $this->_ArrivingBy = null;
      $this->_FacilityRequested = null;
      $this->_Comments = null;
      $this->_Created = null;
    }      
           
    public function setReservationId($reservationId) { 
      if (!is_string($reservationId) || strlen(chop($reservationId)) == 0)
        throw new Exception('Illegal Reservation ID {' . $reservationId . '}');
      else
        $this->_ReservationId = chop(chop($reservationId));
    }
    public function setFirstName($firstName) { 
      if (!is_string($firstName) || strlen(chop($firstName)) == 0)
        throw new Exception('Illegal First Name {' . $firstName . '}');
      else
        $this->_FirstName = chop($firstName);
    }
    public function setLastName($lastName) { 
      if (!is_string($lastName) || strlen(chop($lastName)) == 0)
        throw new Exception('Illegal Last Name {' . $lastName . '}');
      else
        $this->_LastName = chop($lastName);
    }
    public function setArrivalDate($arrivalDate) { 
      if (!is_string($arrivalDate) || strlen(chop($arrivalDate)) == 0)
        throw new Exception('Illegal Arrival Date {' . $arrivalDate . '}');
      else
        $this->_ArrivalDate = chop($arrivalDate);
    }

    public function setNumberOfPersons($numberOfPersons) { 
      if (!is_string($numberOfPersons) || strlen(chop($numberOfPersons)) == 0)
        throw new Exception('Illegal Number of Persons {' . $numberOfPersons . '}');
      else
        $this->_NumberOfPersons = chop($numberOfPersons);
    }

    public function setNumberOfNights($numberOfNights) { 
      if (!is_string($numberOfNights) || strlen(chop($numberOfNights)) == 0)
        throw new Exception('Illegal Number of Nights {' . $numberOfNights . '}');
      else
        $this->_NumberOfNights = chop($numberOfNights);
    }

    public function setEmail($email) { 
      if (!is_string($email) || strlen(chop($email)) == 0)
        throw new Exception('Illegal Email {' . $email . '}');
      else
        $this->_Email = chop($email);
    }

    public function setPhone($phone) { 
      if (!is_string($phone) || strlen(chop($phone)) == 0)
        throw new Exception('Illegal Phone {' . $phone . '}');
      else
        $this->_Phone = chop($phone);
    }

    public function setArrivingBy($arrivingBy) { 
      if (!is_string($arrivingBy) 
		|| strlen(chop($arrivingBy)) == 0
		|| (strrpos("Car,Boat,Air,Other", chop($arrivingBy))=== false) 	)
        throw new Exception('Illegal means of arrival {' . $arrivingBy . '}');
      else
        $this->_ArrivingBy = chop($arrivingBy);
    }
	
    public function setFacilityRequested($facilityRequested) { 
      if (!is_string($facilityRequested) 
		|| strlen(chop($facilityRequested)) == 0
		|| (strrpos("Room,Suite,Meeting Room,Grand Ballroom,Other", chop($facilityRequested))=== false) 	)
        throw new Exception('Illegal Facility Requested {' . $facilityRequested . '}');
      else
        $this->_FacilityRequested = chop($facilityRequested);
    }
    public function setComments($comments) { 
      if (!is_string($comments) || strlen(chop($comments)) == 0){
        # no action
      } else {
        $this->_Comments = chop($comments);
      }
    }

    public function setCreated($created) { 
      if (!is_string($created) || strlen(chop($created)) == 0){
        # no action
      } else {
        $this->_Created = chop($created);
      }
    }

	public function getReservationId(){ return $this->_ReservationId; }
	public function getFirstName(){ return $this->_FirstName; }
	public function getLastName(){ return $this->_LastName; }
	public function getArrivalDate(){ return $this->_ArrivalDate; }
	public function getNumberOfPersons(){ return $this->_NumberOfPersons; }
	public function getNumberOfNights(){ return $this->_NumberOfNights; }
	public function getEmail(){ return $this->_Email; }
	public function getPhone(){ return $this->_Phone; }
	public function getArrivingBy(){ return $this->_ArrivingBy; }
	public function getFacilityRequested(){ return $this->_FacilityRequested; }
	public function getComments(){ return $this->_Comments; }
	public function getCreated(){ return $this->_Created; }
           
    public function __toString() {
      $txt = "";
      $txt .= "Reservation ID: " . $this->_ReservationId . "<br />";
      $txt .= "First Name: " . $this->_FirstName . "<br />";
      $txt .= "Last Name: " . $this->_LastName . "<br />";
      $txt .= "Arrival Date: " . $this->_ArrivalDate . "<br />";
      $txt .= "Number Of Persons: " . $this->_NumberOfPersons . "<br />";
      $txt .= "Number Of Nights: " . $this->_NumberOfNights . "<br />";
      $txt .= "Email: " . $this->_Email . "<br />";
      $txt .= "Phone: " . $this->_Phone . "<br />";
      $txt .= "Arriving By: " . $this->_ArrivingBy . "<br />";
      $txt .= "Facility Requested: " . $this->_FacilityRequested . "<br />";
      $txt .= "Comments: " . $this->_Comments . "<br />";
      $txt .= "Created: " . $this->_Created . "<br />";
      
      return $txt;
    }      
}        
?>