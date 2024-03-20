/*
We're constantly improving the code you see. 
Please share your feedback here: https://form.asana.com/?k=uvp-HPgd3_hyoXRBw1IcNg&d=1152665201300829
*/

import React from "react";
import "./style.css";

export const Buttons = ({
  className,
  groupClassName,
  overlapGroupClassName,
  stopClassName,
  groupClassNameOverride,
  overlapClassName,
  startClassName,
  overlapWrapperClassName,
  overlapClassNameOverride,
  setClassName,
  overlapWrapperClassNameOverride,
  overlapGroupClassNameOverride,
  resetClassName,
}) => {
  return (
    <div className={`buttons ${className}`}>
      <button className={`group-12 ${groupClassName}`}>
        <div className={`overlap-group-2 ${overlapGroupClassName}`}>
          <div className={`stop ${stopClassName}`}>Stop</div>
        </div>
      </button>
      <button className={`group-13 ${groupClassNameOverride}`}>
        <div className={`overlap-3 ${overlapClassName}`}>
          <div className={`start ${startClassName}`}>Start</div>
        </div>
      </button>
      <button className={`group-14 ${overlapWrapperClassName}`}>
        <div className={`overlap-group-2 ${overlapClassNameOverride}`}>
          <div className={`set ${setClassName}`}>Set</div>
        </div>
      </button>
      <button className={`group-15 ${overlapWrapperClassNameOverride}`}>
        <div className={`overlap-3 ${overlapGroupClassNameOverride}`}>
          <div className={`reset ${resetClassName}`}>Reset</div>
        </div>
      </button>
    </div>
  );
};
