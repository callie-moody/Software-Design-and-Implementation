import React from 'react';
import { withRouter } from 'react-router-dom';

// import { connect } from 'react-redux';
import logo from '../img/logo.png';
import miniLogo from '../img/miniLogo.png';
import '../styles/welcomeStyle.scss';

const Welcome = (props) => {
  return (
    <div className="verticalCenter">
      <h1 className="verticalCenterText">Welcome</h1>
      <div className="verticalCenter">
        <img className="logo" alt="Order of The White Lotus Logo" src={logo} />
      </div>
      <p className="verticalCenterText">Sign In</p>
      <div className="signInContainer verticalCenter">
        <input
          className="input"
          // value={smallImg1}
          // onChange={(event) => setsmallImg1(event.target.value)}
          placeholder="Username"
        />
        <div className="marginBottom" />
        <input
          className="input"
          // value={smallImg1}
          // onChange={(event) => setsmallImg1(event.target.value)}
          placeholder="Password"
        />
        <div className="marginBottom" />
        <button onClick={() => { }} className="brownButton" type="button">Sign In</button>
        <div className="marginBottom" />
        <button onClick={() => { }} className="brownButton" type="button">Sign Up</button>
        <div className="marginBottom" />
        <div className="row">
          <div className="divider" />
          <img className="miniLogo" alt="mini logo" src={miniLogo} />
          <div className="divider" />
        </div>

        <div className="marginBottom" />
        <button onClick={() => { props.history.push('/sudoku'); }} className="brownButton" type="button">Continue as Guest</button>

      </div>
    </div>
  );
};

export default withRouter(Welcome);
