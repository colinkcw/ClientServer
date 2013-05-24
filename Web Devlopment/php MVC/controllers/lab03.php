<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of lab03
 *
 * @author Colin
 */
class lab03 extends Application {
    function index(){
        //create the body of for lab 3
        $this->data['pagebody'] = "lab03";
        // give the page a name
        $this->data['pagetitle'] = 'Lab03 XML';
        // import the display helper file
        $this->load->helper('display');
        // use the displa file function to import the data from the xml file
        $this->data['myxml'] = display_file('./data/WadgeColin4711lab03.xml');
        // render the page
        $this->render();
    }
}

?>
