<?php

if (!defined('BASEPATH'))
    exit('No direct script access allowed');

require APPPATH . '/libraries/rest_controller.php';

/**
 * Default controller for COMP4711 Lab Solutions
 */
class user extends Rest_controller {

    function __construct() {
        parent::__construct();
        // error hanldeing congig
        set_exception_handler(array($this, '_ohoh'));
        set_error_handler(array($this, '_oopsy'));
    }
//-------------------------------------------------------------------------------------
    /*
     * returns a representation of all users or one user
     */
    function index_get() {
        $key = $this->get('id');

        if (!$key) {
            $this->response($this->users->getAll_array(), 200);
        } else {
            if (!$this->users->exists($key))
                $this->response(array('error_message' => 'User not found!'), 404);
            $result = $this->users->get($key);
            if ($result != null)
                $this->response($result, 200);
            else
                $this->response(array('error_message' => 'Problem retrieving User!'), 404);
        }
    }

    function index_post() {
        $key = $this->get('id');
        if ($this->users->exists($key))
            $this->response(array('error_message' => 'user id already used!'), 409);
        $record = array_merge(array('id' => $key), $_POST);
        $this->users->add($record);
        $this->response(array('ok'), 200);
    }
/*
 * upadte user
 */
    function index_put() {
        $key = $this->get('id');
        if (!$this->users->exists($key))
            $this->response(array('error_message' => 'user not found!'), 404);
        $record = array_merge(array('id' => $key), $this->_put_args);

        // artificial business rule for lab 11B
        if ($record['role'] == '')
            $this->response(array('error_message' => 'Description cannot be empty'), 406);
        if ($record['name'] == '')
            $this->response(array('error_message' => 'Name cannot be empty'), 406);

        $this->users->update($record);
        $this->response(array('ok'), 200);
    }
/**
 *deleate a user 
 */
    function index_delete() {
        $key = $this->get('id');
        if (!$this->users->exists($key))
            $this->response(array('error_message' => 'User not found!'), 404);
        $this->users->delete($key);
        $this->response(array('ok'), 200);
    }
//---------------------------------------------------------
    function _ohoh($exception) {
        
//        http_send_status(501);
        print_r($exception);
    }

    function _oopsy($code, $message) {
//        http_send_status(499);
        print_r(array('error_message' => 'PHP ERROR! ' . $message));
    }

}

/* End of file welcome.php */
/* Location: ./application/controllers/welcome.php */