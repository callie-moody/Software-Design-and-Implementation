import axios from 'axios';
// keys for actiontypes
export const ActionTypes = {
  CHANGE_BOARD: 'CHANGE_BOARD',
};
export const ROOT_URL = 'http://localhost:9090/api';

export function startBE() {
  return () => {
    axios.get(`${ROOT_URL}`).then((response) => {
      console.log(`Response for startBE${response.message}`);
    }).catch((error) => {
      console.log(`Error in startBE: ${error}`);
    });
  };
}

export function resetBoard() {
  const board = [['0', '0', '0', '0', '0', '0', '0', '0', '0'],
    ['0', '0', '0', '0', '0', '0', '0', '0', '0'], ['0', '0', '0', '0', '0', '0', '0', '0', '0'], ['0', '0', '0', '0', '0', '0', '0', '0', '0'], ['0', '0', '0', '0', '0', '0', '0', '0', '0'],
    ['0', '0', '0', '0', '0', '0', '0', '0', '0'], ['0', '0', '0', '0', '0', '0', '0', '0', '0'], ['0', '0', '0', '0', '0', '0', '0', '0', '0'], ['0', '0', '0', '0', '0', '0', '0', '0', '0']];
  return {
    type: ActionTypes.CHANGE_BOARD,
    payload: board,
  };
}

export function editBoard(id, number, board, setBoardEdited) {
  const rowColumn = id.split(',');
  const newBoard = [...board];
  newBoard[rowColumn[0]][rowColumn[1]] = number;
  setBoardEdited((curr) => !curr);
  return {
    type: ActionTypes.CHANGE_BOARD,
    payload: newBoard,
  };
}

export function create() {
  return (dispatch) => {
    axios.get(`${ROOT_URL}/create`).then((response) => {
      dispatch({
        type: ActionTypes.CHANGE_BOARD,
        payload: response.data,
      });
    }).catch((error) => {
      console.log(`Error in create: ${error}`);
      dispatch({ type: ActionTypes.ERROR, payload: { message: 'There is an error while CREATING sudoku', data: error } });
    });
  };
}

export function solve(board) {
  return (dispatch) => {
    axios.post(`${ROOT_URL}/solve`, { board }).then((response) => {
      console.log(response.data);
      dispatch({
        type: ActionTypes.CHANGE_BOARD,
        payload: response.data,
      });
    }).catch((error) => {
      console.log(`Error in Solve: ${error}`);
      dispatch({ type: ActionTypes.ERROR, payload: { message: 'There is an error while SOLVING sudoku', data: error } });
    });
  };
}
