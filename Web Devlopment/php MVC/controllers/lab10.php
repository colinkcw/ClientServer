<?php
    class lab10 extends Application{
           
        var $remote_server = "comp4711.local";
        var $remote_port = 8080;
        
        function __construct(){
            parent::__construct();
            $this->load->library('xmlrpc');
            $this->load->model('population');
             $this->xmlrpc->server('http://' . $this->remote_server . ':' . $this->remote_port . '/lab10server');
        }
        function index() {
            // import the helper classes
            $this->load->helper('display');
            //$this->load->model('Population');
            $this->data['pagebody'] = "lab10";
            // create a population object
            //$pop = new population();
            // build the table to get the city and area values
             //$pop->buildTable();
            // call the getCity method to get the names of all the citys and towns
            $this->data['city'] = $this->getTheAreas();//
            $this->render();
        }

       // function for getting and displaying the city summary
       function otherwork(){
           // assign the page that will contain the city summary
           $this->data['pagebody'] = "lab07A";
           // get the value passed from the form
           $requested = $this->input->post('requested');
           // load the model class
          // $this->load->model('population');
           // get the information that will be used in the summary
           //$results = $this->population->buildCitySummary($requested);//
           $results = $this->buildReport($requested);
           // assign the given results to the data array
           $this->data['city'] = $results;
           $this->render();
       }
       /**
        *get areas remotely 
        */
       function getTheAreas(){
           
        //connect to the server 
        $this->xmlrpc->method('server.getTheCitys');

        $request = array();
        //create the request to be sent
        $this->xmlrpc->request($request);
        // send the parameters to the method
        if (!$this->xmlrpc->send_request()) {
            echo $this->xmlrpc->display_error();
            exit();
        }
        // return the return value from the method
        return $this->xmlrpc->display_response();
           
       }
       
       function buildReport($area){
           // build the summary
           $data = $this->population->buildCitySummary($area);
           return $data;
       }
    }
?>
