import React from 'react';
import '../styles/style.scss';
import {
  BrowserRouter as Router, Route, Switch,
  // NavLink
} from 'react-router-dom';
import Welcome from './welcome';
import Sudoku from './sudoku';

const FallBack = (props) => {
  return <div>URL Not Found</div>;
};

const App = (props) => {
  return (
    <Router>
      {/* <Nav /> */}
      <Switch>
        <Route exact path="/" component={Welcome} />
        <Route path="/sudoku" component={Sudoku} />
        <Route component={FallBack} />
      </Switch>
    </Router>
  );
};

// const Nav = (props) => {
//   return (
//     <nav>
//       <ul>
//         <li><NavLink to="/" exact>Home</NavLink></li>
//         <li><NavLink to="/sudoku">Sudoku</NavLink></li>
//       </ul>
//     </nav>
//   );
// };

export default App;
