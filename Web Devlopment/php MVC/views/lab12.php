<?php
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
?>
<h1>lab 12</h1>
<form action="/lab12/login" method="post">
      <div id=”div1”>
            Userid: <input type="text" name="userid" id="userid" value=""/>
            <input type="button" id="step1" value="Next"/>
          </div>
      <div id="div2">
            Challenge: <input type="text" id="xxx" name="challenge" value=""/>
            <input type="button" id="step2" value="Next"/>
          </div>
      <div id="div3">
            Password: <input type="password" name="password" value=""/>
            <input type="submit" value="Login"/>
          </div>
</form>
<script type="text/javascript" src="/assets/jquery-1.9.1.min.js"></script>
<script>
    $(document).ready( function() {
        $('#div2').hide();
        $('#div3').hide();
        $('#step1').on( "click", function() {
            $.ajax({
                    // the URL for the request
                    url: "/lab12/user/"+$("#userid").val(),
                    // whether this is a POST or GET request
                    type: "GET",
                    // the type of data we expect back
                    dataType : "text",
                    // code to run if the request succeeds;
                    success: function( result ) {
                            $('#xxx').val(result);
                            $("#div2").show();
                            $("#step1").hide();
                    },
                    // code to run if the request fails
                    error: function( xhr, status ) {
                            alert( "Sorry, there was a problem!" );
                    }
            })
        });
        $('#step2').on( "click", function() {
              $.ajax({
                    // the URL for the request
                    url: "/lab12/check/"+$("#xxx").val(),
                    // whether this is a POST or GET request
                    type: "GET",
                    // the type of data we expect back
                    dataType : "text",
                    // code to run if the request succeeds;
                    success: function( result ) {
                            $("#div2").hide();
                            $("#div3").show();
                    },
                    // code to run if the request fails
                    error: function( xhr, status ) {
                            alert( "Sorry, there was a problem!" );
                    }
            })
        });
    });

</script>
