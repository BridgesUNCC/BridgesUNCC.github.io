#!/bin/sh

prefix_with() {
    local prefix=$1
    shift
    for arg
    do
	echo ${prefix}${arg}
    done
}

prepare_assignment_scaffold() {
    local targetfile=$1
    local srcdir=$2

    cd ${srcdir}
    FILES=$(git ls-files)
    cd -
    zip -j -r ${targetfile} $(prefix_with ${srcdir}/ ${FILES})
    
}

check_for_context() {
    #bail if git is not clean
    if ! git diff --quiet ;
    then
	echo git repository is dirty. Commit changes and run script again
	exit 1
    fi
    
    #bail if markdown is not installed
    if [ ! -e "$(which markdown)" ] ;
    then
	echo markdown is not installed. 
	exit 1
    fi

    
    #if ${BRIDGESASSIGNMENT} does not point to bridges assignment repo, bail.
    if ! [ -e ${BRIDGESASSIGNMENT}/isbridgesassignment ];
    then
	echo can not find bridges assignment repository. pass it as parameter 1 to this script.
	exit 1
    fi
}

reset_context() {
    #remove ASSIGNDIR if exist.
    #This is necessary to clean up previous assignment data which may not be included anymore an help making sure all files are up to date.
    if [ -e  ${ASSIGNDIR} ]
    then
	rm -rf ${ASSIGNDIR}
    fi
    
    
    #remove ${HTMLOUTPUT} if it exists
    if [ -e ${HTMLOUTPUT} ]
    then
	rm ${HTMLOUTPUT}
    fi
    
    mkdir ${ASSIGNDIR}
}

writeheader() {
    cat header >> ${HTMLOUTPUT}
}

writefooter() {
    cat footer >> ${HTMLOUTPUT}
}


addgroup() {
    local name=$1

    printf "%s"'<div class="assignmentgroup"> <p>' >> ${HTMLOUTPUT}
    printf "%s" "${name}"  >> ${HTMLOUTPUT}
    printf "%s" '</p> </div>' >> ${HTMLOUTPUT}
    echo >> ${HTMLOUTPUT}
}

addsubgroup() {
    local name=$1

    printf "%s" '<div class="assignmentsubgroup"> <p>' >> ${HTMLOUTPUT}
    printf "%s" "${name}" >> ${HTMLOUTPUT}
    printf "%s" '</p> </div>' >> ${HTMLOUTPUT}
    echo >> ${HTMLOUTPUT}
}


addassignment() {
    local name=$1

    #bail if assignment name is empty
    if [ ! -n "${name}" ]
    then
	MSG="assignment name is empty \"${name}\""
	echo ${MSG}
	REPORT="${REPORT}\n${MSG}"
	exit 1
    fi

    #bail if assignment does not exists in DB
    srcdir=${BRIDGESASSIGNMENT}/assignmentdb/${name}
    if [ ! -d ${srcdir} ]
    then
	MSG="unknown assignment \"${name}\". \(i.e., not found in "${srcdir}" \)"
	echo ${MSG}
	REPORT="${REPORT}\n${MSG}"
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
	    prepare_assignment_scaffold ${targetdir}/c++.zip ${srcdir}/c++
	else
	    MSG="no C++ scaffold for ${name}"
	    echo ${MSG}
	    REPORT="${REPORT}\n${MSG}"
	fi
	if [ -d ${srcdir}/java ];
	then
	    prepare_assignment_scaffold ${targetdir}/java.zip ${srcdir}/java
	else
	    MSG="no JAVA scaffold for ${name}"
	    echo ${MSG}
	    REPORT="${REPORT}\n${MSG}"
	fi
	if [ -d ${srcdir}/python ];
	then
	    prepare_assignment_scaffold ${targetdir}/python.zip ${srcdir}/python
	else
	    MSG="no Python scaffold for ${name}"
	    echo ${MSG}
	    REPORT="${REPORT}\n${MSG}"
	fi
	
	#copy slides if exist
	if [ -e ${srcdir}/slides/slides.pdf ]
	then
	    cp ${srcdir}/slides/slides.pdf ${targetdir}
	fi

	#setup description 
	cp ${srcdir}/README.md ${targetdir} #typically a markdown file
	if [ -d ${srcdir}/figures ] #description may refer to figures
	then
	    cp -r ${srcdir}/figures ${targetdir}
	fi

	#check for an icon
	if [ ! -f ${targetdir}/figures/icon.png ] ; then
	    MSG="no icon for ${name}"
	    echo ${MSG}
	    REPORT="${REPORT}\n${MSG}"
	fi

	#compile markdown
	( cd ${targetdir}; markdown README.md > README.html )
    fi

    prettyname=$name
    if [ -e ${srcdir}/prettyname ]
    then
	prettyname=$(cat ${srcdir}/prettyname)
    else
	MSG="no prettyname for ${name}"
	echo ${MSG}
	REPORT="${REPORT}\n${MSG}"
    fi

    shortdescription=""
    if [ -e ${srcdir}/shortdescription ]
    then
	shortdescription=$(cat ${srcdir}/shortdescription)
    else
	MSG="no shortdescription for ${name}"
	echo ${MSG}
	REPORT="${REPORT}\n${MSG}"
    fi
    
    
    #output HTML
    echo '<div class="assignment">'  >> ${HTMLOUTPUT}

    #if there is an icon, use it
    if [ -f ${targetdir}/figures/icon.png ] ; then
	echo "<div class=\"assignmenticon\"><img src=\"assignments/${targetdir}/figures/icon.png\" /></div>" >> ${HTMLOUTPUT}
	#else
	 ##Warning already reported
	 #MSG="no icon for ${name}"
	 #echo ${MSG}
	 #REPORT="${REPORT}\n${MSG}"
    fi

    echo '<div class="assignmentmain">' >> ${HTMLOUTPUT}
    echo '<p>' >> ${HTMLOUTPUT}
    echo '<div class="assignmentname">' ${prettyname}. '</div>' >> ${HTMLOUTPUT} #name
    echo '<div class="assignmentshortdesc">' ${shortdescription} '</div>' >> ${HTMLOUTPUT} #shortdesck
    if [ -e ${targetdir}/README.html ] ; #description
    then
	echo "<a href=\"assignments/${targetdir}/README.html\">[Description]</a> "  >> ${HTMLOUTPUT}
    else
	MSG="no description for ${name}"
	echo ${MSG}
	REPORT="${REPORT}\n${MSG}"
    fi
    if [ -e ${targetdir}/slides.pdf ] ; #description
    then
	echo "<a href=\"assignments/${targetdir}/slides.pdf\">[presentation slides]</a> "  >> ${HTMLOUTPUT}
    fi
    #scaffold links
    if [ -e ${targetdir}/c++.zip ] ; 
    then
	echo "<a href=\"assignments/${targetdir}/c++.zip\">[C++ scaffold]</a> "  >> ${HTMLOUTPUT}
    fi
    if [ -e ${targetdir}/java.zip ] ; 
    then
	echo "<a href=\"assignments/${targetdir}/java.zip\">[Java scaffold]</a> "  >> ${HTMLOUTPUT}
    fi
    if [ -e ${targetdir}/python.zip ] ; 
    then
	echo "<a href=\"assignments/${targetdir}/python.zip\">[Python scaffold]</a> "  >> ${HTMLOUTPUT}
    fi
    echo '</p>' >> ${HTMLOUTPUT}
    echo '</div>' >> ${HTMLOUTPUT}
    echo '</div>' >> ${HTMLOUTPUT}
    
}
