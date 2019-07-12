#!/bin/sh

TestUserId="bridges_public"
TestApiKey="997924677918"

for i in *.java
do
	sed -i "" s/"YOUR_USER_ID"/$TestUserId/ $i
	sed -i "" s/"YOUR_API_KEY"/$TestApiKey/ $i
done
