
<p>Select an area...</p>
<form action="/lab07/work" method="post">
<select name="requested">
{areas}
<option value="{name}">{name}</option>
{/areas}
</select>
 <input type="submit" name="mysubmit" value="Submit Post!" />
</form>

<p>Select A City...</p>
<form action="/lab07/otherwork" method="post">
<select name="requested">
{city}
<option value="{name}">{name}</option>
{/city}
</select>
 <input type="submit" name="mysubmit" value="Submit Post!" />
</form>