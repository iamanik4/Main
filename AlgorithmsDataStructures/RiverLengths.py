'''
Problem Statement:
==================
Given a 2-d array of potentially unequal height and width containing only 0s and 1s. Each 0 represents land and
each 1 represents part of a river. A river consists of any number of 1s that are either horizontally or vertically
adjacent(but not diagonally adjacent). The number of adjacent 1s forming a river determine its size. Write a 
function that returns an array of the sizes of all rivers represented in the input matrix. Note that these sizes do
not need to be in any particular order.
'''

def riverLengths(array2d):
    lengths = []
    visited = [[False for nodes in row]for row in array2d]

    for i in range(len(array2d)):
        for j in range(len(array2d[i])):
            if visited[i][j]:
                continue
            traverseNodes(array2d, i, j, visited, lengths)
    return lengths

def traverseNodes(array2d, i, j, visited, lengths):
    currentRiverSize = 0
    nodesToExplore = [[i,j]]

    while(len(nodesToExplore)):
        currentNode = nodesToExplore.pop()
        i = currentNode[0]
        j = currentNode[1]
        if visited[i][j]:
            continue
        visited[i][j] = True
        if array2d[i][j] == 0:
            continue
        currentRiverSize += 1
        unvisitedNeighbors = getUnvisitedNeighbors(i,j,array2d,visited)
        for neighbor in unvisitedNeighbors:
            nodesToExplore.append(neighbor)

    if currentRiverSize > 0:
        lengths.append(currentRiverSize)

def getUnvisitedNeighbors(i,j,array2d,visited):
    unvisitedNeighbors = []
    if i>0 and not visited[i-1][j]:
        unvisitedNeighbors.append([i-1,j])
    if i<len(array2d)-1 and not visited[i+1][j]:
        unvisitedNeighbors.append([i+1,j])
    if j>0 and not visited[i][j-1]:
        unvisitedNeighbors.append([i,j-1])
    if j<len(array2d[i])-1 and not visited[i][j+1]:
        unvisitedNeighbors.append([i,j+1])
    
    return unvisitedNeighbors

array2d = [
            [1,0,0,1,0],
            [1,0,1,0,0],
            [0,0,1,0,1],
            [1,0,1,0,1],
            [1,0,1,1,0],
          ]

print(riverLengths(array2d))