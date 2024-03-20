/*
We're constantly improving the code you see. 
Please share your feedback here: https://form.asana.com/?k=uvp-HPgd3_hyoXRBw1IcNg&d=1152665201300829
*/

import React from "react";
import { Link } from "react-router-dom";
import "./style.css";

export const Intro = ({ className }) => {
  return (
    <div className={`intro ${className}`}>
      <div className="dropdown">
        <button className="component-3">
          <div className="theories-explanation-3">Experiments</div>
        </button>
        <div className="dropdown-content-experiments">
          <Link className="a" to="/simulation-hover"><button className="text1">2 DOF Hover</button></Link>
          <Link className="a" to="/simulation-ballbalance"><button className="text1">2 DOF Ball Balance</button></Link>
          <Link className="a" to="/simulation-servo"><button className="text1">Servo Base Unit</button></Link>
          <Link className="a" to="/simulation-pendulum"><button className="text1">Linear Inverted Pendulum</button></Link>
        </div>
      </div>
      <button className="component-2">
        <div className="theories-explanation-2">Reservation</div>
      </button>
      <div className="dropdown">
        <button className="component-1">
          <div className="theories-explanation-1">Theories Explanation</div>
        </button>
        <div className="dropdown-content-theories">
          <Link className="a" to="/#"><button className="text1">Cascaded PID</button></Link>
          <Link className="a" to="/#"><button className="text1">LQR</button></Link>
        </div>
      </div>

      <p className="p">your gate to learn control</p>
      <img
        className="home-banner"
        alt="Home banner"
        src="https://c.animaapp.com/8gKnAxyl/img/home-banner-1-1-2@2x.png"
      />
    </div>
  );
};
