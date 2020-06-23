#!/bin/sh

wget http://bridgesuncc.github.io/sw/bridges-java-3.1.0.jar -O ~/bridges-java.jar

cat >> ~/.profile <<EOF

if [ "\${CLASSPATH}" = "" ] ;
then
	export CLASSPATH=.:~/bridges-java.jar
else
	export CLASSPATH=\${CLASSPATH}:~/bridges-java.jar
fi

EOF
