<?php

class lab06 extends Application {

    function index() {
        $city_array = array();
        $this->load->helper('display');
        $this->load->model('Population');
        $this->data['pagebody'] = "lab06";
        $this->data['report_title'] = "population By Region";
        $pop = new population();
        $this->data['row'] = $pop->buildTable();
        $this->render();
    }

}

?>
