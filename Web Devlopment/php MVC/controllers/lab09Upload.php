<?php

class lab09Upload extends Application {

    function index() {
        $config = array();
        $this->load->model('Population');
        $this->restrict('admin');
        $config['upload_path'] = './data/uploads/';
        $config['allowed_types'] = '*';
        $config['max_size'] = '100';
        $config['max_width'] = '1024';
        $config['max_height'] = '768';

        $this->load->library('upload', $config);

        if (!$this->upload->do_upload()) {
            // something went wrong
            $error = array('error' => $this->upload->display_errors());
          //  $this->data['errors'] = $error;
            $this->load->view('lab09', $error);
        } else {
            // all seems ok
            $uploadeddata = $this->upload->data();
            // get the file name
            $filename = $uploadeddata['full_path'];
            // create a new population object
            $pop = new Population();
            // upload the data from the file
            $data = $pop->process_upload($filename);
               // add the data to the xml and create a new xml call updated
            $foo = $pop->add_data($data);

        }

        $this->data['myxml'] = display_file('./data/updated.xml');
        $this->data['pagebody'] = 'lab09Results';
        $this->render();
    }

}

?>
