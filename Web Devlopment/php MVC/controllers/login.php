<?php

if (!defined('BASEPATH'))
    exit('No direct script access allowed');

/**
 * Default controller for COMP4711 Lab Solutions
 */
class login extends Application {

    function __construct() {
        parent::__construct();
    }

    /**
     * Default entry point.
     * Yes, we are using view templating.
     */
    function index() {
        $this->data['pagetitle'] = 'log in Now';
        $this->data['pagebody'] = 'login';
        $this->data['target'] = $this->session->userdata('target');
        $this->render();
    }

    function submit() {
        $key = $_POST['userid'];
        $password = md5($_POST['password']);
        $user = $this->users->get($key);
        //what if no such user
        if($user == null){
            redirect('/');
        }
        // check the password
        if ($password == (string) $user->password) {
            // we have a winner
            $this->session->set_userdata('userID', $key);
            $this->session->set_userdata('userName', $user->name);
            $this->session->set_userdata('userRole', $user->role);
            redirect($this->session->userdata('target'));
        } else {
            redirect('/');
            exit;
        }
    }

}

/* End of file welcome.php */
/* Location: ./application/controllers/welcome.php */