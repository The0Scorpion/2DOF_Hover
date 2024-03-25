/*
We're constantly improving the code you see. 
Please share your feedback here: https://form.asana.com/?k=uvp-HPgd3_hyoXRBw1IcNg&d=1152665201300829
navbar.jsx
*/

import React from "react";
import "./style.css";
import { Link } from "react-router-dom"

export const NavBar = ({ className }) => {
  return (
    <div className={`nav-bar ${className}`}>
      <div className="overlap-4">
        <img className="mask-group-2" alt="Mask group" src="https://c.animaapp.com/zqIJEW6i/img/mask-group-22@2x.png" />
      </div>
      <div className="group-wrapper">
        <Link to="/">
          <img
            className="mask-group-3"
            alt="Mask group"
            src="https://c.animaapp.com/zqIJEW6i/img/mask-group-23@2x.png"
          />
          <img
            className="mask-group-3"
            alt="Mask group"
            src="https://c.animaapp.com/zqIJEW6i/img/mask-group-24@2x.png"
          />
          <img
            className="mask-group-3"
            alt="Mask group"
            src="https://c.animaapp.com/zqIJEW6i/img/mask-group-25@2x.png"
          />
        </Link>
      </div>
      <div className="group-21">
        <button className="log-in"><Link to="/log-in"><p className="p">Log In</p></Link></button>
        <button className="text-wrapper-9"><Link to="/registration"><p className="p">Register</p></Link></button>
        <button className="text-wrapper-10"><Link to="/"><p className="p">Contact us</p></Link></button>
        <button className="text-wrapper-11"><Link to="/"><p className="p">About us</p></Link></button>
        <button className="reservation"><Link to="/"><p className="p">Reservation</p></Link></button>
        <div className="dropdown-theory">
          <button className="theories-explanation">Theories Explanation</button>
          <div className="dropdown-content-theories">
            <Link to="/#"><button className="p2">Cascaded PID</button></Link>
            <Link to="/#"><button className="p2">LQR</button></Link>
          </div>
        </div>
        <div className={'dropdown-exp'}>
          <button className="experiments">Experiments</button>
          <div className="dropdown-content-experiments">
            <Link to="/simulation-hover"><button className="p2">2 DOF Hover</button></Link>
            <Link to="/simulation-ballbalance"><button className="p2">2 DOF Ball Balance</button></Link>
            <Link to="/simulation-servo"><button className="p2">Servo Base Unit</button></Link>
            <Link to="/simulation-pendulum"><button className="p2">Linear Inverted Pendulum</button></Link>
          </div>
        </div>
      </div>
    </div>
  );
};
