// the starting point for your redux store
// this defines what your store state will look like
import { combineReducers } from 'redux';

import BoardReducer from './boardReducer';

const rootReducer = combineReducers({
  boardData: BoardReducer,
});

export default rootReducer;
