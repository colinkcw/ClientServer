<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
?>
<div>
    <h1>{report_title}</h1>
    <table>
        <tr>
            <th>Name</th>
            <th>Area Type</th>
            <th>2006</th>
            <th>2007</th>
            <th>2008</th>
            <th>2009</th>
            <th>2010</th>
            <th>2011</th>
            <th>2012</th>
            <th>% Change</th>
        </tr>
        {row}
        <tr>
            <td>{name}</td>
            <td>{type}</td>
            <td>{2006}</td>
            <td>{2007}</td>
            <td>{2008}</td>
            <td>{2009}</td>
            <td>{2010}</td>
            <td>{2011}</td>
            <td>{2012}</td>
            <td>{change}</td>
        </tr>
        {/row}
    </table>
</div>