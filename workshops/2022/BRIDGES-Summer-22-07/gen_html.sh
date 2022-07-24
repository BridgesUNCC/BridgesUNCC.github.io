#!/bin/sh

for dir in openswim/* ;
do
    (
	cd $dir
	cmark-gfm --extension table README.md > README.html
    )
done
