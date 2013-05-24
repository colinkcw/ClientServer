<?php
    class lab07 extends Application{
           
        
        function index() {
            // import the helper classes
            $this->load->helper('display');
            $this->load->model('Population');
            $this->data['pagebody'] = "lab07";
            // create a population object
            $pop = new population();
            // build the table to get the city and area values
            $pop->buildTable();
            // call the getArea method to get the names of the areas types
            $this->data['areas'] = $pop->getAreas();
            // call the getCity method to get the names of all the citys and towns
            $this->data['city'] = $pop->getCitys();
            $this->render();
        }
        // function for getting and displaying the area summary
        function work(){
            // assign the page that will contain the area summary
            $this->data['pagebody'] = "lab07B";
            // get the value passed from the form
            $requested = $this->input->post('requested');
            // load the model class
            $this->load->model('population');
            // get the information that will be used in the Summary
            $results = $this->population->buildAreaSummary($requested);
            // assign the given results to the data array
            $this->data['areas'] = $results;
            // assign the type name to the data array
            $this->data['type'] = (string)$requested;
            $this->render();
        }
       // function for getting and displaying the city summary
       function otherwork(){
           // assign the page that will contain the city summary
           $this->data['pagebody'] = "lab07A";
           // get the value passed from the form
           $requested = $this->input->post('requested');
           // load the model class
           $this->load->model('population');
           // get the information that will be used in the summary
           $results = $this->population->buildCitySummary($requested);
           // assign the given results to the data array
           $this->data['city'] = $results;
           $this->render();
       }
    }
?>
