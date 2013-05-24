
<p>Select A City...</p>
<form action="/lab10/otherwork" method="post">
<select name="requested">
{city}
<option value="{name}">{name}</option>
{/city}
</select>
 <input type="submit" name="mysubmit" value="Submit Post!" />
</form>