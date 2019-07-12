#!/bin/sh


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
    printf "%s" ${name}  >> ${HTMLOUTPUT}
    printf "%s" '</p> </div>' >> ${HTMLOUTPUT}
    echo >> ${HTMLOUTPUT}
}

addsubgroup() {
    name=$1

    printf "%s" '<div class="assignmentsubgroup"> <p>' >> ${HTMLOUTPUT}
    printf "%s" ${name} >> ${HTMLOUTPUT}
    printf "%s" '</p> </div>' >> ${HTMLOUTPUT}
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
	    cp -r ${srcdir}/figures ${targetdir}
	fi
	( cd ${targetdir}; markdown README.md > README.html ) #compile markdown
    fi

    prettyname=$name
    if [ -e ${srcdir}/prettyname ]
    then
	prettyname=$(cat ${srcdir}/prettyname)
    fi

    shortdescription=""
    if [ -e ${srcdir}/shortdescription ]
    then
	shortdescription=$(cat ${srcdir}/shortdescription)
    fi
    
    
    #output HTML
    echo '<div class="assignment">'  >> ${HTMLOUTPUT}
    echo '<p>' >> ${HTMLOUTPUT}
    echo '<div class="assignmentname">' ${prettyname}. '</div>' >> ${HTMLOUTPUT} #name
    echo '<div class="assignmentshortdesc">' ${shortdescription} '</div>' >> ${HTMLOUTPUT} #shortdesck
    if [ -e ${targetdir}/README.html ] ; #description
    then
	echo "<a href=\"assignments/${targetdir}/README.html\">[Description]</a> "  >> ${HTMLOUTPUT}
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
addassignment "4-GraphEQ"
addassignment "9-ShortestPathOSM"

addgroup "Algorithms"
addsubgroup "Complexity"

addsubgroup "Greedy Algorithms"
addassignment "23-MountainPaths"

writefooter

git add ${HTMLOUTPUT}
git add ${ASSIGNDIR}
git commit -am "updating assignments"
