<?php

/*
 * Model function, that creates the table data to be viewed on site
 */
if (!defined('BASEPATH'))
    exit('No direct script access allowed');

class Population extends CI_Model {

    //array that will hold the citys
    var $city_array = array();
    // array that will hold the area types
    var $area_array = array();
    var $root;

    // constructor
    function __construct() {
        parent::__construct();

        $this->root = simplexml_load_file('./data/lab05.xml');

        foreach ($this->root->Region->Areas->AreaID as $areas) {
            $this->area_array[(string) $areas['code']] = (string) $areas;
        }
    }

    function buildTable() {
        $source = $this->root;
        // array that holds the citys
        $carray = array();
        // array that will hold all the information of the table
        $table = array();
        // create a array to hold the citys relative to there initials
        foreach ($source->Region->Districts->City as $cities) {
            $this->city_array[(string) $cities['initials']] = $cities;
        }
        // create a array that holds the areas relative to there area codes
        /*  foreach ($source->Region->Areas->AreaID as $areas) {
          $this->area_array[(string) $areas['code']] = (string)$areas;
          } */
        //go through each category once in order to match up the area codes with the citys
        foreach ($source->Region->PopulationInfo->Population->Districtcategory as $dist) {
            $prev = 0; // holds the previous years population value
            $change = 0; // holds the change between the last and current year population
            // go through each number element in order to get the city relative to the area
            foreach ($dist->Number as $nam) {
                // add the city name and type to the citys array element
                $carray[(string) $this->city_array[(string) $nam['civic']]] = array(
                    'type' => $this->area_array[(string) $dist['category']],
                    'name' => $this->city_array[(string) $nam['civic']]
                );
                //go through each population element to exratct the year and amout for each city
                foreach ($source->Region->PopulationInfo->Population as $pop) {
                    // go through each district 
                    foreach ($pop->Districtcategory as $district) {
                        // go through each number to get the population for the city
                        foreach ($district->Number as $num) {
                            // match up the population data with the proper city
                            if ((string) $num['civic'] == (string) $nam['civic']) {
                                $carray[(string) $this->city_array[(string) $nam['civic']]][(string) $pop['year']] = $num;
                                $change = $num - $prev; // calculate the amount changed between the current and last year
                                $prev = $num;
                            }
                        }
                    }
                }
                // calculate the change percentage and round the number to two decimal places
                $changed = ($change / $num) * 100;
                $rounded = round($changed, 2);
                // add the number to the array
                $carray[(string) $this->city_array[(string) $nam['civic']]]['change'] = $rounded;
                //if a better way of processing the xml is possible please let me know, using 5 loops does not seem
                // to be the most elegant way thank you.
                // add the array holding the city data to the table array
                array_push($table, $carray[(string) $this->city_array[(string) $nam['civic']]]);
            }
        }

        return $table;
    }

    // gets the citys within the table
    function getCitys() {
        // used for incrementing through the array
        $i = 0;
        // array that will hold the final data to be returned
        $return_array = array();
        // loop through the city array 
        foreach ($this->city_array as $city) {
            // assign the name of each city as an element of the return array
            $return_array[$i] = array('name' => $city);
            $i++;
        }
        return $return_array;
    }

    // gets the areas within the table
    function getAreas() {
        $i = 0;
        // array that will hold the final data to be returned
        $return_array = array();
        // loop through the area array 
        foreach ($this->area_array as $area) {
            // assign the name of each area as an element of the return array
            $return_array[$i] = array('name' => $area);
            $i++;
        }
        return $return_array;
    }

    function buildAreaSummary($requested) {
        $i = 0;
        // array to be returned
        $array_return = array();
        // build the table to access the data
        $table_array = $this->buildTable();
        // loop through each city in the table
        foreach ($table_array as $table) {
            // if the city area matches the requested area 
            if ((string) $table['type'] == (string) $requested) {
                // put that city array into the return array
                array_push($array_return, $table);
            }
        }
        return $array_return;
    }

    function buildCitySummary($requested) {
        $i = 0;
        // array to be returned
        $array_return = array();
        // build the table to access the data
        $table_array = $this->buildTable();
        // loop through each city in the table
        foreach ($table_array as $table) {
            // if the city area matches the requested city 
            if ((string) $table['name'] == (string) $requested) {
                // put that city array into the return array
                array_push($array_return, $table);
            }
        }
        return $array_return;
    }

    function buildAreaTypes() {
        // array to be returned
        $array_return = array();
        $source = $this->root;
        // go through the Districtcategorys and build the headers for the table
        foreach ($source->xpath('//Districtcategory/@category') as $code) {
            $array_return[(string) $code] = array('name' => $code);
        }
        return $array_return;
    }

    function buildAreaChange() {
        // holds the total population for the year
        $yearTotal = 0;
        // variable that will hold the percent of the population for the current area
        $i = 0;
        $array_return = array();
        $source = $this->root;
        // go through each population node and extract the year
        foreach ($source->xpath('//Population/@year')as $year) {
            // add the year to a array with the same year for the name
            $array_return[(string) $year] = array('year' => $year);
            // calculate the total popluation for that year by going through each Number element
            foreach ($source->xpath('//Population[@year = ' . $year . ']/Districtcategory/Number') as $num) {
                $yearTotal += $num;
            }
            // go through each districtcategory to find the percent of the population
            foreach ($source->xpath('//Population[@year = ' . $year . ']/Districtcategory/@category') as $dist) {
                $distpercent = 0;
                $distsum = 0;
                // go through each number element for the given category and add them together to get the percent 
                foreach ($source->xpath('//Population[@year = ' . $year . ']/Districtcategory[@category = "' . $dist . '"]/Number') as $distNum) {
                    $distsum += $distNum;
                }
                // calculate percent
                $distpercent = ($distsum / $yearTotal) * 100;
                $distpercent = round($distpercent, 2);
                $array_return[(string) $year]['' . $i . ''] = $distpercent;
                $i++;
            }
            $i = 0;


            //$array_return[(string) $year] = array('year' => $year);
            $yearTotal = 0;
        }
        return $array_return;
    }

    function process_upload($file) {
        $row = 1;
        $return_array = array();
        //open the file for reading
        if (($handle = fopen($file, "r")) !== FALSE) {
            // while we can get a line out of the file proceede through loop
            while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
                // get the length of the line
                $num = count($data);
                // skip the first row since sgc is not needed
                if ($row != 1) {
                    //loop through the elements in the line
                    for ($c = 0; $c < $num; $c++) {
                        // if the data is not blank lines
                        if ($data[$c]) {
                            // if c equals 0 create a new array
                            if ($c == 0) {
                                $return_array[(string) $data[$c]] = array();
                            }
                            // assign the elements of the line to the array
                            $return_array[(string) $data[0]][$c] = $data[$c];
                        }
                    }
                }
                $row++;
            }
            fclose($handle);
        }
        return $return_array;
    }

    function add_data($add) {

        $xml = simplexml_load_file('./data/lab05.xml');

        $cityElement = $xml->Region->Districts;
        // loop thorugh each element of the info array
        foreach ($add as $info) {
            // the area name is the first element
            $area = (string) $info['1'];
            // the initials are the first two letters of the name
            $initial = substr((string) $info['1'], 0, 2);
            // the category is the third element in the array
            $mycat = (string) $info['2'];
            $i = 3;
            // add the city and intials to the districts 
            $newcity = $cityElement->addChild('City', $area);
            $newcity->addAttribute('initials', $initial);
            // go through each years population 
            foreach ($xml->xpath('//Population')as $pop) {
                // go through each category 
                foreach ($pop->Districtcategory as $cat) {
                    // match the category with the new elements category
                    if ($cat['category'] == $mycat) {
                        // add the information 
                        $newPop = $cat->addChild('Number', (string) $info[$i]);
                        $newPop->addAttribute('civic', $initial);
                        $i++;
                    }
                }
            }
        }
        // save the xml 
        $xml->asXml('./data/updated.xml');
    }

}

