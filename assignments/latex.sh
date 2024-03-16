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
\column{.32\linewidth}
\begin{block}{$groupname}
\tiny
EOF
    groupsopen="yes"
}

addsubgroup() {
    local subgroupname=$1
    closesubgroup
    
    cat <<EOF

    \textbf{${subgroupname}:}
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

    if [ "${assignmentopen}" ];
    then
	cat <<EOF
;
EOF
    fi
    echo -n \ \ \ \ \ \ $prettyname

    assignmentopen="yes"
}

closegroup() {
    closesubgroup

    if [ "${groupsopen}" ];
    then
	cat<<EOF
\end{block}

EOF
	groupsopen=""
    fi
}

closesubgroup() {
    closeassignment
    if [ "${subgroupsopen}" ];
    then
	cat<<EOF

EOF
	subgroupsopen=""
    fi
}

closeassignment() {
    if [ "${assignmentopen}" ];
    then
	assignmentopen=""
    fi
}



closeout() {
    closegroup
 
}

cat<<EOF
\begin{columns}[T]
EOF
    
. ./data.sh

closeout

cat<<EOF
\end{columns}
EOF
