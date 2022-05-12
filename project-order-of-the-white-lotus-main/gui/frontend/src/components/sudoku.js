/* eslint-disable react/no-array-index-key */
/* eslint-disable no-plusplus */
import React, { useState, useEffect } from 'react';
import { connect } from 'react-redux';
import miniLogo from '../img/miniLogo.png';
import logo from '../img/logo.png';
import '../styles/sudokuStyle.scss';

import {
  solve, create, startBE, resetBoard, editBoard,
} from '../actions';

const Sudoku = (props) => {
  const [started, setStarted] = useState(false);
  const [boardEdited, setBoardEdited] = useState(false);
  const [boardCreated, setBoardCreated] = useState(false);
  const [board, setBoard] = useState(new Array(9));

  if (started === false) {
    props.startBE();
    setStarted(true);
  }

  const createBoard = () => {
    // create a 1D array
    const count = 9;

    const newBoard = [...board];
    // create a 2D array
    for (let i = 0; i < count; i++) {
      newBoard[i] = [0, 0, 0, 0, 0, 0, 0, 0, 0];
    }
    setBoard(newBoard);
  };

  const displayBoard = (boardToDisplay) => {
    return (
      boardToDisplay.map((row, rowIndex) => {
        return (
          <div key={rowIndex}>
            {row.map((column, columnIndex) => {
              return (
                <input
                  key={`${rowIndex},${columnIndex}`}
                  className="cell"
                  id={`${rowIndex},${columnIndex}`}
                  // value={boardToDisplay[rowIndex][columnIndex]}
                  value={boardToDisplay[rowIndex][columnIndex] === '0' || boardToDisplay[rowIndex][columnIndex] === 0 ? '' : boardToDisplay[rowIndex][columnIndex]}
                  onChange={(event) => props.editBoard(event.target.id, event.target.value, props.board, setBoardEdited)}
                />
              );
            })}
          </div>
        );
      })
    );
  };

  useEffect(() => {
    if (props.board === undefined) { displayBoard(board); } else {
      displayBoard(props.board);
    }
  }, [boardEdited]);

  if (boardCreated === false) {
    createBoard();
    setBoardCreated(true);
  }

  return (
    <div className="sudokuContainer">
      <div className="row">
        <img className="miniLogoSudoku" alt="mini logo" src={miniLogo} />
        <h2 className="verticalCenterText">Sudoku Challenge</h2>
        <img className="miniLogoSudoku" alt="mini logo" src={miniLogo} />
      </div>
      <p>You can input your own board directly by filling in the cells and press the Solve Board button!</p>
      {props.board ? displayBoard(props.board) : displayBoard(board)}

      <div className="marginBottom" />
      <div className="marginBottom" />

      <div className="signInContainer verticalCenter">
        <button onClick={() => { props.create(); }} className="brownButton" type="button">Create a Board</button>
        <div className="marginBottom" />

        <button onClick={() => { props.solve(props.board); }} className="brownButton" type="button">Solve!</button>
        <div className="marginBottom" />

        <button onClick={() => { props.resetBoard(); }} className="brownButton" type="button">Reset the Board</button>
      </div>

      <div className="marginBottom" />
      <div className="marginBottom" />
      <div className="marginBottom" />
      <img className="logoSudoku" alt="mini logo" src={logo} />

      <p>Made with Love,</p>
      <p>Vi Tran</p>
      <p>Callie Moody</p>
      <p>Vanessa Perez-Robles</p>
      <p>Connor Coale</p>

    </div>
  );
};

// connects particular parts of redux state to this components props
const mapStateToProps = (state) => (
  {
    board: state.boardData.board,
  }
);

const mapDispatchToProps = {
  startBE, solve, create, resetBoard, editBoard,
};

export default connect(mapStateToProps, mapDispatchToProps)(Sudoku);
