<?php

/**
 * Controller for COMP4711 Lab 10.
 * This is the REST client.
 * This is identical to lab 10, except for the RES bit.
 */
define('RESTFUL', true); // are we doing REST or just faking it?

class Lab11 extends Application {

    // Assume that the "remote" server is ourselves
    var $remote_server;
    var $remote_port;

    function __construct() {
        parent::__construct();

        // setup for application framework
        $this->load->helper('display');
        $this->data['pagetitle'] = 'COMP4711 Lab 11 Solution';

        // Assume that the "remote" server is ourselves
        $this->remote_server = 'http://' . $_SERVER['SERVER_NAME'];
        $this->remote_server = 'http://' . 'comp4711.local';
        $this->remote_port = $_SERVER['SERVER_PORT'];

        // toggle the remote server to use my hosted solution
        /* if (RESTFUL) {
          $this->remote_server = 'http://comp4711.bcitxml.com';
          $this->remote_port = 80;
          }
         */
        // setup RESTful client
        $this->rest->initialize(array('server' => $this->remote_server));
        $this->rest->option(CURLOPT_PORT, $this->remote_port);
    }

    /**
     * Default entry point.
     * No work to do - the story is told in the view.
     */
    function index() {
        $this->data['pagebody'] = 'lab11';

        if (RESTFUL)
            $retrieved = $this->rest->get('/user');
        else
            $retrieved = $this->users->getAll_array(); // for local test

            
//print_r($retrieved);
        $this->data['users'] = (array) $retrieved;
        $this->render();
    }

    /**
     * Subcontroller: work.
     * Given a product code, show its form
     */
    function work($code) {

        if (RESTFUL)
            $retrieved = $this->rest->get('/product/code/' . $code);
        else
            $retrieved = $this->products->get($code);

        // Merge the retrieved record fields with view parameters
        $this->data = array_merge($this->data, (array) $retrieved);
        $this->data['pagebody'] = 'lab11product';
        $this->render();
    }

    function add1() {
        $this->data['pagebody'] = 'lab11user';
        $this->data['adding'] = true;
        $this->render();
    }

    function addUser() {
        $this->data['pagebody'] = 'lab11';
        $id = $this->input->post('id');
        $name = $this->input->post('name');
        $password = $this->input->post('password');
        $role = $this->input->post('role');
        $this->users->insert_db($id, $name, $password, $role);



        if (RESTFUL)
            $retrieved = $this->rest->get('/user');
        else
            $retrieved = $this->users->getAll_array(); // for local test
            
//print_r($retrieved);
        $this->data['users'] = (array) $retrieved;

        $this->render();
    }

    /**
     * Update the product 
     */
    function update($code) {
        $record = array('id' => $code);
        $record = array_merge($record, $_POST);
        

        if (RESTFUL)
            $retrieved = $this->rest->put('/user/id/' . $code, $record);
        else
            $retrieved = $this->users->update($record);
        $this->index();
    }

    /**
     * Delete the product
     */
    function delete($code) {
        if (RESTFUL)
            $retrieved = $this->rest->delete('/user/id/' . $code);
        else
            $retrieved = $this->users->delete($code);
        $this->index();
    }

}

/* End of file lab10.php */
/* Location: ./application/controllers/lab10.php */