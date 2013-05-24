$(this).css({'border-width': '0px', 'outline': 'none'})
    .wrap('<div id="sq" class="divclearable"></div>')
    .parent()
    .attr('class', $(this).attr('class') + ' divclearable')
    .append('<a class="clearlink" href="javascript:"></a>');
 
$('.clearlink')
    .attr('title', 'Click to clear this textbox')
    .click(function() {
 
        $(this).prev().val('').focus();
 
});