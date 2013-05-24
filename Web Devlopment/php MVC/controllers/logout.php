<?php

if (!defined('BASEPATH'))
    exit('No direct script access allowed');

/**
 * Default controller for COMP4711 Lab Solutions
 */
class Logout extends Application {
  function index() {
    $this->session->sess_destroy();
    Redirect('/');
  }

}

/* End of file welcome.php */
/* Location: ./application/controllers/welcome.php */