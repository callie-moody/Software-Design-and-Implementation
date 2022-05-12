# Sudoku Front End

### Project Overview
Sudoku is a web platform that allows the user to input sudoku boards to have the website solve for them, or create a unique sudoku board

### Link to Figma: 
https://www.figma.com/file/9nvw49db2NCPdFoJjQYmLT/Sudoku-UI?node-id=19%3A293

### Project Architecture
Front-end:
React
React-router
Redux
Redux thunk
Axios

### Content
#### Axios calls:
1. startBE: call the index route of the backend to start the backend. This function will also result in the BE generating the makeFile
2. resetBoard: reset the board to an empty board by changing the board's state to an empty board
3. editBoard: take in the location of the number changed by the user, the number the user inputted, and the board from redux. Change the board accordingly
4. create: send a request to BE to create a sudoku board
5. solve: Take in a board to be solved, send a request to the BE to solve the sudoku board

#### Components:
1. Sudoku: the FE portion for the page with the sudoku board
2. Welcome: the FE portion for the page with a welcome message


### Developer Information
To run locally:

Clone front-end repo into a local directory
Run npm install to install all node dependencies
Run npm start to start running the site locally at localhost:8080
Go to the backend repo and follow instructions on its README to get the server running locally at localhost:9090. 

### Notes
Website is not deployed at the moment but planned to be released

The current development flow has all pull requests merging into the 'main' branch, which is the equivalent of the 'master' branch on most repos. 


### Authors
Vi Tran D'23
Connor Coale D'22
Vanessa Perez-Robles D'23
Callie Moody D'24




