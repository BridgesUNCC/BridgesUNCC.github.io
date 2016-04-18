(function()
{
hljs.configure({useBR:true,tabReplace:''});
var codeBlocks = document.getElementsByTagName("code");
for(var i=0;i<codeBlocks.length;i++)//For Each Code Tag
{
	/* Fixes line breaking and indenting */
	codeBlocks[i].innerHTML = codeBlocks[i].innerHTML
	.replace(/=/g,"<span class='hljs-symbol'>=</span>")
	.replace(/,/g,"<span class='commas'>,</span>")
	.replace(/\./g,"<span class='hljs-selector-tag'>.</span>")
	.replace(/:/g,"<span class='hljs-selector-tag'>:</span>")
	.replace(/&amp;/g,"<span class='hljs-symbol'>&amp</span>")
	.replace(/&lt;/g,"<span class='hljs-template-tag'>&lt</span>")
	.replace(/&gt;/g,"<span class='hljs-template-tag'>&gt</span>")
	.replace(/;/g,"<span class='hljs-section'>;</span>")
	.replace(/\(/g,"<span class='parenthesies'>(</span>")
	.replace(/\)/g,"<span class='parenthesies'>)</span>")
	.replace(/string/ig,"<span class='hljs-built_in'>String</span>");

	//Remove all White Space Surrounding New Line Characters and leading New Line
	codeBlocks[i].innerHTML = codeBlocks[i].innerHTML.replace(/ *\n */g,"\n").replace("\n","");
	//Add div tags for tab insertion
	codeBlocks[i].innerHTML = codeBlocks[i].innerHTML.replace(/{\n/g,"{<div class='tab'>").replace(/\n}/g,"</div>}");
	//Add tabs
	var tabBlocks = document.querySelectorAll("code div.tab");
	var TAB = "&nbsp;&nbsp;&nbsp;";
	for(var j=tabBlocks.length-1;j>=0;j--)//For Each tab Tag
	{
		tabBlocks[j].innerHTML = tabBlocks[j].innerHTML
		.replace(new RegExp(TAB,"g"),TAB+TAB)
		.replace(/^/g,TAB)
		.replace(new RegExp("\n"+TAB,"g"),"\n")
		.replace(/\n/g,"\n"+TAB)
		.replace(/}/g,TAB+"}");
	}
	//Change New Line Characters to Line Breaks
	codeBlocks[i].innerHTML = codeBlocks[i].innerHTML.replace(/\n/g,"<br/>");
	hljs.highlightBlock(codeBlocks[i]);
}
})();