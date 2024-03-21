/*
We're constantly improving the code you see. 
Please share your feedback here: https://form.asana.com/?k=uvp-HPgd3_hyoXRBw1IcNg&d=1152665201300829
*/

import React from "react";
import {Link} from "react-router-dom"
import "./style.css";

export const NavLogWrapper = ({ 
  className,
  maskgroup, 
}) => {
  return (
    <div className={`nav-log-wrapper ${className}`}>
      <div className="div-wrapper">
        <div className="frame">
          <div className="div">
            <div className="div-wrapper">
              <div className="overlap-2">
                <div className="mask-group">
                  <div className="div-wrapper">
                    <div className="div">
                      <div className="div-wrapper">
                        <div className="div">
                          <div className="div-wrapper">
                            <div className="div">
                              <div className="overlap-group-wrapper">
                                <div className="overlap-group-2">
                                  <div className="group" />
                                  <div className="group" />
                                  <div className="mask-group">
                                    <div className="frame-2">
                                      <div className="group-2" />
                                      <div className="group-3" />
                                      <div className="group-4" />
                                    </div>
                                  </div>
                                </div>
                              </div>
                            </div>
                          </div>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
                <Link to="/">
                <img
                  className={`mask-group ${maskgroup}`}
                  alt="Mask group"
                  src="https://c.animaapp.com/lSpjHlHF/img/mask-group-6@2x.png"
                />
                <img
                  className={`mask-group ${maskgroup}`}
                  alt="Mask group"
                  src="https://c.animaapp.com/lSpjHlHF/img/mask-group-7@2x.png"
                />
                <img
                  className={`mask-group ${maskgroup}`}
                  alt="Mask group"
                  src="https://c.animaapp.com/lSpjHlHF/img/mask-group-8@2x.png"
                />
                </Link>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
};
