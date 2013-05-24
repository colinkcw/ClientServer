<?php
/*
 * View for lab 10 
 */
?>
<div>
    <fieldset>
        <legend>User List</legend>
        <div>
            <table>
                <tr>
                    <th>ID</th>
                    <th>Type</th>
                </tr>
                {users}
                <tr>
                    <td>{id}</td>
                    <td>{role}</td>
                </tr>
                {/users}
            </table>
        </div>
    </fieldset>
    <a href="lab11/add1">add one </a>
</div>