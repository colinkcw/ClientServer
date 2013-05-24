<?php

/**
 * XML-RPC for COMP4711 Lab 10
 * 
 */
class Lab10server extends CI_Controller {

    function __construct() {
        parent::__construct();
        // load the necessary libarys
        $this->load->library('xmlrpc');
        $this->load->library('xmlrpcs');
        $this->load->model('population');
    }

    // Entry point to the XML-RPC server
    function index() {
        // link the method call to the actuall method on the server side
        $config['functions']['server.getTheCitys'] = array('function' => 'Lab10server.handle_Citys');
        $config['object'] = $this;
        // initialze the method
        $this->xmlrpcs->initialize($config);
        $this->xmlrpcs->serve();
    }

    // Handle a category list requess
    function handle_Citys($request) {
        // build the table
        $this->population->buildTable();
        // get the citys information
        $answer = $this->population->getCitys();

        $response = array();
        // for each returned object from the method
        foreach ($answer as $row)
            // put the object into a struct inside the response array
            $response[] = array($row, 'struct');
        $response = array($response, 'struct');
        // send the final object as the answer
        return $this->xmlrpc->send_response($response);
    }
}

/* End of file lab12serverX.php */
/* Location: ./application/controllers/lab12serverX.php */
