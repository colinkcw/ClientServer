<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

class lab05 extends Application {

    function index() {
//create the body of for lab 4
        $this->load->helper('common');
        $this->load->helper('display');
        $this->load->helper('form');
        $this->data['pagebody'] = "lab05";
        $this->load->helper('display');
        $this->data['lab05xml'] = display_file('./data/lab05.xml');
        $this->data['lab05schema'] = display_file('./data/lab05.xsd');
        $this->data['lab05validation'] = validate_xml_schema('./data/lab05.xml','./data/lab05.xsd');
        $this->render();
    }

}

?>
