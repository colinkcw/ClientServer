<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
class lab04 extends Application {
    function index(){
        //create the body of for lab 4
        $this->load->helper('common');
        $this->data['pagebody'] = "lab04";
        // give the page a name
        $this->data['pagetitle'] = 'Lab04 XML and DTD';
        // import the display helper file
        $this->load->helper('display');
        // use the display file function to import the data from the xml file
        $this->data['lab04xml'] = display_file('./data/lab04.xml');
        // use the display file function to import the data from the dtd
        $this->data['lab04dtd'] = display_file('./data/lab04.dtd');
        // use the validate xml function to validate the given xml file agianst the dtd
        // if successfull it will display success
        $this->data['xmlvalidate'] =  validate_xml('./data/lab04.xml');
        // render the page
        $this->render();
    }
}
?>
