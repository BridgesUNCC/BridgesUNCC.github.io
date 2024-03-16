#!/bin/sh

BRIDGESASSIGNMENT=$1

    #if ${BRIDGESASSIGNMENT} does not point to bridges assignment repo, bail.
    if ! [ -e ${BRIDGESASSIGNMENT}/isbridgesassignment ];
    then
	echo can not find bridges assignment repository. pass it as parameter 1 to this script.
	exit 1
    fi


addgroup() {
    local groupname=$1
    closegroup
    
    cat <<EOF
$groupname
\begin{itemize}
EOF
    groupsopen="yes"
}

addsubgroup() {
    local subgroupname=$1
    closesubgroup
    
    cat <<EOF
  \item $subgroupname
  \begin{itemize}
EOF
    subgroupsopen="yes"
}

addassignment() {
    local assignment=$1

    srcdir=${BRIDGESASSIGNMENT}/assignmentdb/${assignment}
    
    prettyname=$assignment
    if [ -e ${srcdir}/prettyname ]
    then
	prettyname=$(cat ${srcdir}/prettyname)
    fi

    
    cat <<EOF
    \item $prettyname
EOF
}

closegroup() {
    if [ "${groupsopen}" ];
    then
	cat<<EOF
\end{itemize}
EOF
	groupsopen=""
    fi
}

closesubgroup() {
    if [ "${subgroupsopen}" ];
    then
	cat<<EOF
  \end{itemize}
EOF
	subgroupsopen=""
    fi
}



closeout() {
    closesubgroup
    closegroup
 
}

. ./data.sh

closeout
