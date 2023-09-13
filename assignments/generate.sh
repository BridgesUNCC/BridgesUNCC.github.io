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
addassignment "56-2DIndexing"

addsubgroup "Tests and Conditions"
addassignment "34-GameTutorials"
addassignment "19-Bugstomp"

addsubgroup "Loops"
addassignment "25-Patterns"
addassignment "23-MountainPaths"
addassignment "33-AudioMixing"
addassignment "52-AudioWave"
addassignment "56-2DIndexing"
addassignment "55-FrequencyPlayer"
addassignment "68-MusicNotes-CS2"
addassignment "65-Reddit"


addsubgroup "Input/Output"
addassignment "10-HurricaneTracker"

addsubgroup "1D Arrays"
addassignment "33-AudioMixing"
addassignment "55-FrequencyPlayer"
addassignment "68-MusicNotes-CS2"
addassignment "65-Reddit"

addsubgroup "2D Arrays"
addassignment "6-GridSquareFill"
addassignment "7-GridLyrics"
addassignment "16-ImagePuzzle"
addassignment "40-ImageProcessing"
addassignment "56-2DIndexing"
addassignment "52-AudioWave"

addsubgroup "Games"
addassignment "17-ControlsTutorial"
addassignment "18-ControlsTutorialTwo"
addassignment "11-2048Game"
addassignment "13-InfiniteRunner"
addassignment "20-Minesweeper"
addassignment "21-RaceCar"
addassignment "22-Snake"
addassignment "32-TicTacToe"
addassignment "36-Pong"
addassignment "35-ConnectFour"
addassignment "41-SpaceInvaders"
addassignment "69-SnakeQueue"


addsubgroup "Audio"
addassignment "55-FrequencyPlayer"
addassignment "52-AudioWave"
addassignment "33-AudioMixing"
addassignment "68-MusicNotes-CS2"

addsubgroup "Simulation"
addassignment "14-SpreadingFire"
addassignment "15-FallingSand"

addgroup "Data Structure"
addsubgroup "LinkedList"
addassignment "1-ListIMDB"
addassignment "2-ListEQ"

addsubgroup "Stacks and Queues"
addassignment "12-AStarMaze"
addassignment "26-TowersOfHanoi"
addassignment "22-Snake"
addassignment "69-SnakeQueue"

addsubgroup "Trees"
addassignment "5-BST_Earthquakes"
addassignment "8-PQBook"
addassignment "24-ImageCompressionKdTree"
addassignment "39-BookDistance"
addassignment "60-Quadtree-CityData"

addsubgroup "Hashing, Hash Tables, and Hash Maps"
addassignment "8-PQBook"
addassignment "39-BookDistance"

addsubgroup "Graphs"
addassignment "12-AStarMaze"
addassignment "3-GraphBaconNumber"
addassignment "30-TemporalBaconNumber"
addassignment "4-GraphEQ"
addassignment "9-ShortestPathOSM"
addassignment "31-TemporalPageRank"
addassignment "39-BookDistance"


addgroup "Algorithms"
addsubgroup "Big Oh"
addassignment "28-BigOhMatters"

addsubgroup "Sorting"
addassignment "29-SortingBenchmark"

addsubgroup "Brute Force"
addassignment "64-Voronoi_Diagram"

addsubgroup "Divide and Conquer"
addassignment "59-ConvexHull_CityData"


addsubgroup "Complexity of Graph Problems"
addassignment "9-ShortestPathOSM"
addassignment "30-TemporalBaconNumber"
addassignment "31-TemporalPageRank"

addsubgroup "Spanning Tree"
addassignment "44-MST-Cities"

addsubgroup "Spatial Problems"
addassignment "43-SpatialIndexing"
addassignment "59-ConvexHull_CityData"
addassignment "60-Quadtree-CityData"

addsubgroup "Greedy Algorithms"
addassignment "23-MountainPaths"
addassignment "9-ShortestPathOSM"
addassignment "38-GeologicalSurvey"
addassignment "44-MST-Cities"

addsubgroup "Dynamic Programing"
addassignment "23-MountainPaths"
addassignment "9-ShortestPathOSM"

addsubgroup "NP-Complete problems"
addassignment "38-GeologicalSurvey"

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
