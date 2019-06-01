#!/bin/sh


#bail if git is not clean
if ! git diff --quiet ;
then
    echo git repository is dirty. Commit changes and run script again
    exit 1
fi


ASSIGNDIR=data/
BRIDGESASSIGNMENT=$1

#if ${BRIDGESASSIGNMENT} does not point to bridges assignment repo, bail.
if ! [ -e ${BRIDGESASSIGNMENT}/isbridgesassignment ];
then
    echo can not find bridges assignment repository. pass it as parameter 1 to this script.
    exit 1
fi

#remove ASSIGNDIR if exist.
#This is necessary to clean up previous assignment data which may not be included anymore an help making sure all files are up to date.
if [ -e  ${ASSIGNDIR} ]
then
    rm -rf ${ASSIGNDIR}
fi

HTMLOUTPUT=out.html

#remove ${HTMLOUTPUT} if it exists
if [ -e ${HTMLOUTPUT} ]
then
    rm ${HTMLOUTPUT}
fi

mkdir ${ASSIGNDIR}


writeheader() {
    cat header >> ${HTMLOUTPUT}
}

writefooter() {
    cat footer >> ${HTMLOUTPUT}
}


addgroup() {
    name=$1

    echo -n '<div class="assignmentgroup"> <p>' >> ${HTMLOUTPUT}
    echo -n ${name}  >> ${HTMLOUTPUT}
    echo -n '</p> </div>' >> ${HTMLOUTPUT}
    echo >> ${HTMLOUTPUT}
}

addsubgroup() {
    name=$1

    echo -n '<div class="assignmentsubgroup"> <p>' >> ${HTMLOUTPUT}
    echo -n ${name} >> ${HTMLOUTPUT}
    echo -n '</p> </div>' >> ${HTMLOUTPUT}
    echo >> ${HTMLOUTPUT}
}


addassignment() {
    name=$1

    #bail if assignment name is empty
    if [ ! -n "${name}" ]
    then
	echo assignment name is empty \"${name}\"
	exit 1
    fi

    #bail if assignment does not exists in DB
    srcdir=${BRIDGESASSIGNMENT}/assignmentdb/${name}
    if [ ! -d ${srcdir} ]
    then
	echo unknown assignment \"${name}\". \(i.e., not found in "${srcdir}" \)
	exit 1
    fi

    #copy assignment data if not already there
    targetdir=${ASSIGNDIR}/${name}
    if [ ! -d ${targetdir} ]
    then
	mkdir ${targetdir}

	#generate scaffold archives
	if [ -d ${srcdir}/c++ ];
	then
	    zip -j -r ${targetdir}/c++.zip ${srcdir}/c++
	else
	    echo no C++ scaffold for ${name}
	fi
	if [ -d ${srcdir}/java ];
	then
	    zip -j -r ${targetdir}/java.zip ${srcdir}/java
	else
	    echo no JAVA scaffold for ${name}
	fi
	if [ -d ${srcdir}/python ];
	then
	    zip -j -r ${targetdir}/python.zip ${srcdir}/python
	else
	    echo no Python scaffold for ${name}
	fi
	
	#copy slides if exist
	if [ -e ${srcdir}/slides/slides.pdf ]
	then
	    cp ${srcdir}/slides/slides.pdf ${targetdir}
	fi

	#setup description 
	cp ${srcdir}/README.md ${targetdir} #typicially a markdown file
	if [ -d ${srcdir}/figures ] #description may refer to figures
	then
	    cp ${srcdir}/figures ${targetdir}
	fi
	( cd ${targetdir}; markdown README.md > README.html ) #compile markdown
    fi
    
    #output HTML
    echo '<div class="assignment">'  >> ${HTMLOUTPUT}
    echo ${name}. >> ${HTMLOUTPUT} #name
    if [ -e ${targetdir}/README.html ] ; #description
    then
	echo "<a href=\"${targetdir}/README.html\">[description]</a> "  >> ${HTMLOUTPUT}
    fi
    if [ -e ${targetdir}/slides.pdf ] ; #description
    then
	echo "<a href=\"${targetdir}/slides.pdf\">[presentation slides]</a> "  >> ${HTMLOUTPUT}
    fi
    #scaffold links
    if [ -e ${targetdir}/c++.zip ] ; 
    then
	echo "<a href=\"${targetdir}/c++.zip\">[C++ scaffold]</a> "  >> ${HTMLOUTPUT}
    fi
    if [ -e ${targetdir}/java.zip ] ; 
    then
	echo "<a href=\"${targetdir}/java.zip\">[Java scaffold]</a> "  >> ${HTMLOUTPUT}
    fi
    if [ -e ${targetdir}/python.zip ] ; 
    then
	echo "<a href=\"${targetdir}/python.zip\">[Python scaffold]</a> "  >> ${HTMLOUTPUT}
    fi

    echo '</div>' >> ${HTMLOUTPUT}
    
}

writeheader

addgroup "CS1"
addsubgroup "Loops"
addassignment "6-GridSquareFill"

addgroup "Data Structure"
addsubgroup "graphs"
addassignment "9-ShortestPathOSM"

writefooter

#git add ${ASSIGNDIR}
#git commit -am "updating assignments"
