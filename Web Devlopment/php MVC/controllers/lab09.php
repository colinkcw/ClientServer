<?php

class lab09 extends Application {
    
    function index() {
        // import the helper classes
        $foo = array();
        $this->restrict('admin');
        $this->data['pagebody'] = "lab09";
        $this->render();
    }

}
?>
