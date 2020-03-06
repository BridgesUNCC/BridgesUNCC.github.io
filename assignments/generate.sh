#!/bin/sh

REPORT=""

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


ASSIGNDIR=data/
BRIDGESASSIGNMENT=$1
HTMLOUTPUT=../newassignments.html


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

    printf "%s"'<div class="assignmentgroup"> <p>' >> ${HTMLOUTPUT}
    printf "%s" "${name}"  >> ${HTMLOUTPUT}
    printf "%s" '</p> </div>' >> ${HTMLOUTPUT}
    echo >> ${HTMLOUTPUT}
}

addsubgroup() {
    name=$1

    printf "%s" '<div class="assignmentsubgroup"> <p>' >> ${HTMLOUTPUT}
    printf "%s" "${name}" >> ${HTMLOUTPUT}
    printf "%s" '</p> </div>' >> ${HTMLOUTPUT}
    echo >> ${HTMLOUTPUT}
}


addassignment() {
    name=$1

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
	    zip -j -r ${targetdir}/c++.zip ${srcdir}/c++
	else
	    MSG="no C++ scaffold for ${name}"
	    echo ${MSG}
	    REPORT="${REPORT}\n${MSG}"
	fi
	if [ -d ${srcdir}/java ];
	then
	    zip -j -r ${targetdir}/java.zip ${srcdir}/java
	else
	    MSG="no JAVA scaffold for ${name}"
	    echo ${MSG}
	    REPORT="${REPORT}\n${MSG}"
	fi
	if [ -d ${srcdir}/python ];
	then
	    zip -j -r ${targetdir}/python.zip ${srcdir}/python
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

writeheader

addgroup "CS1"
addsubgroup "Basic API Calls"
addassignment "27-GameGridBasic"


addsubgroup "Tests and Conditions"
addassignment "17-ControlsTutorial"
addassignment "18-ControlsTutorialTwo"
addassignment "19-Bugstomp"

addsubgroup "Loops"
addassignment "25-Patterns"
addassignment "23-MountainPaths"

addsubgroup "Input/Output"
addassignment "10-HurricaneTracker"

addsubgroup "2D Arrays"
addassignment "6-GridSquareFill"
addassignment "7-GridLyrics"
addassignment "16-ImagePuzzle"


addsubgroup "Games"
addassignment "11-2048Game"
addassignment "13-InfiniteRunner"
addassignment "14-SpreadingFire"
addassignment "15-FallingSand"
addassignment "20-Minesweeper"
addassignment "21-RaceCar"
addassignment "22-Snake"
addassignment "32-TicTacToe"

addgroup "Data Structure"
addsubgroup "LinkedList"
addassignment "1-ListIMDB"
addassignment "2-ListEQ"

addsubgroup "Stacks and Queues"
addassignment "12-AStarMaze"
addassignment "26-TowersOfHanoi"
addassignment "22-Snake"

addsubgroup "Trees"
addassignment "5-BstEq"
addassignment "8-PQBook"
addassignment "24-ImageCompressionKdTree"

addsubgroup "Graphs"
addassignment "12-AStarMaze"
addassignment "3-GraphBaconNumber"
addassignment "30-TemporalBaconNumber"
addassignment "4-GraphEQ"
addassignment "9-ShortestPathOSM"
addassignment "31-TemporalPageRank"

addgroup "Algorithms"
addsubgroup "Big Oh"
addassignment "28-BigOhMatters"

addsubgroup "Sorting"
addassignment "29-SortingBenchmark"

addsubgroup "Complexity of Graph Problems"
addassignment "9-ShortestPathOSM"
addassignment "30-TemporalBaconNumber"
addassignment "31-TemporalPageRank"

addsubgroup "Greedy Algorithms"
addassignment "23-MountainPaths"

addsubgroup "Dynamic Programing"
addassignment "23-MountainPaths"

addsubgroup "Multi objective optimization"
addassignment "23-MountainPaths"


writefooter

git add ${HTMLOUTPUT}
git add ${ASSIGNDIR}
git commit -am "updating assignments"


echo ================================
echo              REPORT
echo ================================

echo ${REPORT}
