//tabbing logic
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

function displayCodeSnippet(turnOn, category, caller)
{
    let tabs = document.querySelectorAll("*."+category+" > *");
    for(let i=0;i<tabs.length;i++)
    {
	tabs[i].setAttribute("active", "false");
    }

    caller.setAttribute("active","true");
    document.getElementById(turnOn).setAttribute("active","true");
}

function activateAllTabs() {
    let tabs = document.querySelectorAll("*.tabs > *");
    //console.log(tabs);
    for(let i=tabs.length-1;i>=0;i--)
    {
	tabs[i].click();
    }    

}


//bridges iframe

setTimeout(loadFrame, 1000);

function loadFrame() {
	$('iframe').attr('src', $('iframe').attr('data-src'));
}
