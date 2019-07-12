#!/bin/sh

TestUserId="kalpathi60"
TestApiKey="486749122386"

for i in *.cpp
do
	sed -i "" s/"YOUR_USER_ID"/$TestUserId/ $i
	sed -i "" s/"YOUR_API_KEY"/$TestApiKey/ $i
done
