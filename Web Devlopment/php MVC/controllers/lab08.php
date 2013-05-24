<?php

class lab08 extends Application {

    function index() {
        // import the helper classes
        $foo = array();
        $this->load->helper('display');
        $this->load->model('Population');
        $this->data['pagebody'] = "lab08";
        $pop = new population();
        $this->data['column'] = $pop->buildAreaTypes();
        $this->data['row'] = $pop->buildAreaChange();
        $this->render();
    }

}

?>
