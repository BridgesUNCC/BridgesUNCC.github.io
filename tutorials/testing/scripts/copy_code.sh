#!/bin/sh

#bail if git is not clean
if ! git diff --quiet ;
then
    echo git repository is dirty. Commit changes and run script again
    exit 1
fi

BRIDGESTESTING=$1
#if ${BRIDGESTESTING} does not point to bridges assignment repo, bail.
if ! [ -e ${BRIDGESTESTING}/isbridgestesting ];
then
    echo can not find bridges testing repository. pass it as parameter 1 to this script.
    exit 1
fi

if ! [ -e ../../../isbridgeswebsite ];
then
    echo This script should be run from BridgesUNCC.github.io/tutorials/testing/scripts
    exit 1
fi

( cd ${BRIDGESTESTING}; make make_web )

rm -rf ../c++
mkdir ../c++
cp -r ${BRIDGESTESTING}/c++/web_tutorial_fortheweb/* ../c++/

rm -rf ../java
mkdir ../java
cp -r ${BRIDGESTESTING}/java/web_tutorial_fortheweb/* ../java/

rm -rf ../python
mkdir ../python
cp -r ${BRIDGESTESTING}/python/web_tutorial_fortheweb/* ../python/


for file in ../c++/* ../java/* ../python/*;
do
    case "$file" in
	*.cpp) vim -E -s -c "let g:html_no_progress=1" -c "syntax on" -c \
		   "set ft=cpp" -c "runtime syntax/2html.vim" -cwqa "$file" ;;
	*.h) vim -E -s -c "let g:html_no_progress=1" -c "syntax on" -c \
		 "set ft=cpp" -c "runtime syntax/2html.vim" -cwqa "$file" ;;
	*.java) vim -E -s -c "let g:html_no_progress=1" -c "syntax on" -c \
		    "set ft=java" -c "runtime syntax/2html.vim" -cwqa "$file" ;;
	*.py) vim -E -s -c "let g:html_no_progress=1" -c "syntax on" -c \
		  "set ft=python" -c "runtime syntax/2html.vim" -cwqa "$file" ;;
    esac


    #KR if you see some weird output comment the lines below.
    
    LINENB_END=$(grep -n \</pre\> ${file}.html | cut -d : -f 1)
    LINENB_BEG=$(grep -n \<pre\ id= ${file}.html | cut -d : -f 1)
    
    head -n `echo $LINENB_END | bc` ${file}.html > temp.html
    
    #NBLINE=`wc -l temp.html | cut -d \  -f 1`
    NBLINE=`wc -l < temp.html` #using stdin rather than passing a filename makes wc print ONLY the number of lines (without file names)  
    
    tail -n `echo $NBLINE - $LINENB_BEG + 1 | bc` temp.html > ${file}.html
   
done


git add ../c++
git add ../java
git add ../python

git commit -am "updating codes from bridges-client-testing"
