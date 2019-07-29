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

setTimeout(loadFrame, 1000);

function loadFrame() {
	$('iframe').attr('src', $('iframe').attr('data-src'));
}
