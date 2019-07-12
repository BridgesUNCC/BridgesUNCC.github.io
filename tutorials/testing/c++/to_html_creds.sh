#!/bin/sh

for i in *.cpp   *.h
do
	vim -E -s -c "let g:html_no_progress=1" -c "syntax on" -c \
		"set ft=c" -c "runtime syntax/2html.vim" -cwqa $i
done
