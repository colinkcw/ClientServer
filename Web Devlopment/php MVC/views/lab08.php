
<div>
    <table>
        <tr>
            <td></td>
            {column}
            <td>{name}</td>
            {/column}
        </tr>
        {row}
        <tr>
            <td>{year}</td>
            <?php 
                  
                  $foo = sizeof($column);
                  for($i = 0; $i < $foo ; $i++) {                          
                    echo '<td>{'.$i.'}</td>';
                  }
           ?>  
       {/row}
        </tr>
        
    </table>
</div>