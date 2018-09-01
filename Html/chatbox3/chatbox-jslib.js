var scriptjs = require('scriptjs');
scriptjs('https://code.jquery.com/jquery-3.1.0.min.js', function() {
    L.mapbox.accessToken = 'MyToken';
});
/**
<script src="http://code.jquery.com/jquery-1.11.1.min.js"></script>
<script src="http://code.jquery.com/mobile/1.4.5/jquery.mobile-1.4.5.min.js"></script>
**/
function swapVisibility(tagId)
{
  if($("#"+tagId).is(":hidden"))
  {
    $("#"+tagId).show();
  }
  else
  {
    $("#"+tagId).hide();
  }
}