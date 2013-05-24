<?php
/*
 * View for lab 10 
 */
?>
<div>
    <fieldset>
        <legend>Product List</legend>
        <div>
            <?
              $target = $adding ? "addUser" : "update";  
            ?>
            <? if ($target == "addUser"){?> 
             <form action="/lab11/addUser" method="post">
              <?} else{?>
                 <form action="/lab11/update" method="post">
                     <?}?>
                <table>
                    <tr>
                        <th>Field</th>
                        <th>Value</th>
                    </tr>
                    <tr><td>ID</td>
                        <td><input type="text" name="id" value="{id}"/></td></tr>
                    <tr><td>Name</td>
                        <td><input type="text" name="name" value="{name}"/></td></tr>
                    <tr><td>Password</td>
                        <td><input type="text" name="password" value="{password}"/></td></tr>
                    <tr><td>Role</td>
                        <td><input type="text" name="role" value="{role}"/></td></tr>
                </table>
                <input type="submit" value="Update User"/>
            </form>
      
            <a href="/lab11/delete">Delete this User</a>
        </div>
    </fieldset>
</div>