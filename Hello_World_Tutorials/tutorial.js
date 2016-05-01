function displayCode(param,caller)
{
	var tabs = document.querySelectorAll("*.tabs > *");
	for(var i=0;i<tabs.length;i++)
	{
		tabs[i].setAttribute("active","false");
	}
	var tabContent = document.querySelectorAll("*.tabContents > *");
	for(var i=0;i<tabContent.length;i++)
	{
		tabContent[i].setAttribute("active","false");
	}
	caller.setAttribute("active","true");
	document.getElementById(param).setAttribute("active","true");
}
function preCodeFormat(ele)
{
  var codeBlocks = ele.querySelectorAll('code');   
  for(var i=0;i<codeBlocks.length;i++)
  {
    var str = codeBlocks[i].innerHTML;
    //Finds common indent, then removes to leave only differences
    codeBlocks[i].innerHTML = str.replace(new RegExp("^ {" + str.lastIndexOf(" ",str.search(/\S/)) + "}","gm"),"").trim();
  }
}
function w3IncludeHTML(funct) 
{
  var z, i, a, file, xhttp;
  z = document.getElementsByTagName("*");
  for (i = 0; i < z.length; i++) 
  {
    if (z[i].getAttribute("w3-include-html"))
    {
      a = z[i].cloneNode(false);
      file = z[i].getAttribute("w3-include-html");
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() 
        {
          if (xhttp.readyState == 4 && xhttp.status == 200) 
          {
            a.removeAttribute("w3-include-html");
            a.innerHTML = xhttp.responseText;
            //Apply formating function
            if(!(funct === undefined)){funct(a);}
            else{preCodeFormat(a);}
            //
            z[i].parentNode.replaceChild(a, z[i]);
            w3IncludeHTML(funct);
          }
        }      
      xhttp.open("GET", file, true);
      xhttp.send();
      return;
    }
  }
}
