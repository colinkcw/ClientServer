<?php

/**
 * Controller for COMP4711 Lab 10.
 * This is the REST client.
 * This is identical to lab 12, except for the RES bit.
 */
define('RESTFUL', true); // are we doing REST or just faking it?

class Lab12 extends Application {

    
// constructor
    function __construct() {
        parent::__construct();

        $this->load->helper('display');

    }


    function index() {
        // load the page body 
        $this->data['pagebody'] = 'lab12';

        $this->data['pagetitle'] = 'COMP4711 Lab 12 ';

        $this->render();
    }
    
    //validate a user
    
    function user($userid){
        // get the user related to the id
        $user = $this->users->get($userid);
        // if no user show error message
        if($user == null) {
            show_error('user not found', 405);
        }else{
            // create two random numbers
            $v1 = rand(0,10);
            $v2 = rand(0,10);
            // set the answer to flash data to be retrived at a later time
            echo $v1 . ' + ' .  $v2 . ' =  ?';
            $this->session->set_flashdata('answer', $v1 + $v2);
        }

    }
    
    function check($answer){
        // check the answer that it matches to the anser stored in the flash data
        $correct_answer = $this->session->flashdata('answer');
        // if the correct anser echo scuccess else display error
        if($answer == $correct_answer){
            echo"success";
        }else{
            show_error('try agian',500);
        }
    }
    
    function login(){
        echo"login stuff";
    }

}
