/*
We're constantly improving the code you see. 
Please share your feedback here: https://form.asana.com/?k=uvp-HPgd3_hyoXRBw1IcNg&d=1152665201300829
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
        <button className="log-in">Log In</button>
        <button className="text-wrapper-9">Register</button>
        <button className="text-wrapper-10">Contact</button>
        <button className="text-wrapper-11"><Link to="/">About</Link></button>
      </div>
    </div>
  );
};
