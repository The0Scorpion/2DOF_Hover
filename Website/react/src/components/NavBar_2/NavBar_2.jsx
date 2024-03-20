/*
We're constantly improving the code you see. 
Please share your feedback here: https://form.asana.com/?k=uvp-HPgd3_hyoXRBw1IcNg&d=1152665201300829
*/

import PropTypes from "prop-types";
import React from "react";
import { Link } from "react-router-dom";
import "./style.css";

export const NavBar_2 = ({ className, maskGroup = "https://c.animaapp.com/jrXwmMSX/img/mask-group-13@2x.png" }) => {
  return (
    <div className={`nav-bar-2 ${className}`}>
      <div className="nav-bar-dropdown">
        <button className="group-42">
          <div className="rectangle-8" />
          <div className="rectangle-9" />
          <div className="rectangle-10" />
        </button>
        <div className="dropdown-content-nav">
          <Link className="a" to="/#"><button className="text1">About us</button></Link>
          <Link className="a" to="/#"><button className="text1">Contact us</button></Link>
          <Link className="a" to="/#"><button className="text1">Register</button></Link>
          <Link className="a" to="/#"><button className="text1">Log In</button></Link>
        </div>
      </div>

      <div className="control-chef-high-3">
        <div className="div-4">
          <div className="frame-8">
            <div className="div-4">
              <div className="div-wrapper-3">
                <div className="overlap-9">
                  <Link to="/">
                    <img
                      className="mask-group-7"
                      alt="Mask group"
                      src="https://c.animaapp.com/zqIJEW6i/img/mask-group-16@2x.png"
                    />
                    <img
                      className="mask-group-7"
                      alt="Mask group"
                      src="https://c.animaapp.com/zqIJEW6i/img/mask-group-17@2x.png"
                    />
                    <img
                      className="mask-group-7"
                      alt="Mask group"
                      src="https://c.animaapp.com/zqIJEW6i/img/mask-group-18@2x.png"
                    />
                  </Link>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
};

NavBar_2.propTypes = {
  maskGroup: PropTypes.string,
};
