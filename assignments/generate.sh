#!/bin/sh

. ./util.sh

REPORT=""

ASSIGNDIR=data/
BRIDGESASSIGNMENT=$1
HTMLOUTPUT=../newassignments.html

check_for_context

reset_context



writeheader

addgroup "CS1"
addsubgroup "Basic API Calls"
addassignment "27-GameGridBasic"


addsubgroup "Tests and Conditions"
addassignment "34-GameTutorials"
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
