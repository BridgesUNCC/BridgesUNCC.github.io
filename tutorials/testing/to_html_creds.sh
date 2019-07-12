#!/bin/sh

TestUserId="kalpathi60"
TestApiKey="486749122386"

for i in *.cpp  
do
	sed -i "" s/$TestUserId/"YOUR_USER_ID"/ $i
	sed -i "" s/$TestApiKey/"YOUR_API_KEY"/ $i
	vim -E -s -c "let g:html_no_progress=1" -c "syntax on" -c \
		"set ft=c" -c "runtime syntax/2html.vim" -cwqa $i
done
