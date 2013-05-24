<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
?>
<h1>Uploading something</h1>
<form action="/lab09Upload" method="post" enctype="multipart/form-data">
   What do you want? <input type="file" name="userfile" />
   <input type="submit" value="upload" />
</form>
