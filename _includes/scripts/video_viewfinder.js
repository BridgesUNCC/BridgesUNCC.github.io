function on(vid_ID) {
   document.getElementById(vid_ID).style.display = "block";
   
}

function off(vid_ID) {
  var parent = document.getElementById(vid_ID);
  var iframe = parent.querySelector( 'iframe');
  var iframeSrc = iframe.src;
  iframe.src = iframeSrc;
  parent.style.display = "none";
}