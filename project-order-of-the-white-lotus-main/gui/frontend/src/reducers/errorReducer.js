import { ActionTypes } from '../actions';

const initialState = {
  message: '',
  data: '',
};

const ErrorReducer = (state = initialState, action) => {
  switch (action.type) {
    case ActionTypes.ERROR:
      return { ...state, message: action.payload.message, data: action.payload.data };
    default:
      return state;
  }
};

export default ErrorReducer;
