/*
We're constantly improving the code you see. 
Please share your feedback here: https://form.asana.com/?k=uvp-HPgd3_hyoXRBw1IcNg&d=1152665201300829
*/

import React from "react";
import "./style.css";
import { Link } from "react-router-dom"

export const ButtonIntro = ({
  className,
  theoriesExplanationClassName,
  overlapGroupClassName,
  theoriesExplanationClassNameOverride,
  experimentsClassName,
  overlapClassName,
  divClassName,
  reservationClassName,
  overlapClassNameOverride,
  divClassNameOverride,
}) => {
  return (
    <div className={`button-intro ${className}`}>
      <div className="dropdown">
        <button className={`theories-explanation-4 ${theoriesExplanationClassName}`} >
          <div className={`overlap-group-3 ${overlapGroupClassName}`}>
            <div className={`theories-explanation-5 ${theoriesExplanationClassNameOverride}`}>Theories Explanation</div>
          </div>
        </button>
        <div className="dropdown-content-theories">
          <Link className="a" to="/#"><button className="text1">Cascaded PID</button></Link>
          <Link className="a" to="/#"><button className="text1">LQR</button></Link>
        </div>
      </div>
      <div className={'dropdown'}>
        <button className={`experiments ${experimentsClassName}`} type={"button"} data-toggle={"dropdown"} aria-haspopup={"true"} aria-expanded={"false"}>
          <div className={`overlap-3 ${overlapClassName}`}>
            <div className={`theories-explanation-6 ${divClassName}`}>Experiments</div>
          </div>
        </button>
        <div className="dropdown-content-experiments">
          <Link className="a" to="/simulation-hover"><button className="text1">2 DOF Hover</button></Link>
          <Link className="a" to="/simulation-ballbalance"><button className="text1">2 DOF Ball Balance</button></Link>
          <Link className="a" to="/simulation-servo"><button className="text1">Servo Base Unit</button></Link>
          <Link className="a" to="/simulation-pendulum"><button className="text1">Linear Inverted Pendulum</button></Link>
        </div>
      </div>
      <Link to="/#">
        <button className={`reservation ${reservationClassName}`}>
          <div className={`overlap-4 ${overlapClassNameOverride}`}>
            <div className={`theories-explanation-7 ${divClassNameOverride}`}>Reservation</div>
          </div>
        </button>
      </Link>
    </div>
  );
};
