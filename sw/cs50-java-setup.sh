#!/bin/sh

rm -r bridges-java.jar

wget http://bridgesuncc.github.io/sw/bridges-java-3.2.0.jar -O ~/bridges-java.jar

cat >> ~/.profile <<EOF

if [ "\${CLASSPATH}" = "" ] ;
then
	export CLASSPATH=.:~/bridges-java.jar
else
	export CLASSPATH=\${CLASSPATH}:~/bridges-java.jar
fi

EOF
