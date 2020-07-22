#!/bin/sh

extractversion() {
    cd $1
    git ls-files * | sed 's/\([^/]*\)\/.*/\1/g' | uniq | sort -r | uniq
    cd - > /dev/null 2&>1
}

listversions() {
    versions=`extractversion $1`

    echo \<ul\>
    for v in ${versions};
    do
	echo \ \ \<li\> \<a href=\"http://bridgesuncc.github.io/doc/${1}/${v}/html/index.html\"\>${v}\</a\>\</li\>
    done
    echo \</ul\>
}

cat <<EOF
<!-- DO NOT MANUALLY EDIT THIS FILE. IT IS GENERATED AUTOMATICALLY. READ doc/README.md for details -->

        <h2>BRIDGES documentations</h2>
EOF

cat <<EOF
        <h3>Java</h3>
EOF


listversions java-api


cat <<EOF
        <h3>C++</h3>
EOF


listversions cxx-api


cat <<EOF
        <h3>Python</h3>
EOF


listversions python-api

