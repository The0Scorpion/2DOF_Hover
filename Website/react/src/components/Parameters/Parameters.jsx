/*
We're constantly improving the code you see. 
Please share your feedback here: https://form.asana.com/?k=uvp-HPgd3_hyoXRBw1IcNg&d=1152665201300829
*/

import React from "react";
import "./style.css";

export const Parameters = ({
  className,
  textClassName,
  xPosKpClassName,
  groupClassName,
  overlapGroupClassName,
  xPosKpClassNameOverride,
  textClassNameOverride,
  yPosKpClassName,
  groupClassNameOverride,
  overlapGroupClassNameOverride,
  yPosKpClassNameOverride,
  divClassName,
  xPosKiClassName,
  overlapGroupWrapperClassName,
  xPosKiWrapperClassName,
  xPosKiClassNameOverride,
  divClassNameOverride,
  yPosKiClassName,
  overlapGroupWrapperClassNameOverride,
  yPosKiWrapperClassName,
  yPosKiClassNameOverride,
  textClassName1,
  xPosKdClassName,
  groupClassName1,
  xPosKdWrapperClassName,
  xPosKdClassNameOverride,
  textClassName2,
  yPosKdClassName,
  groupClassName2,
  yPosKdWrapperClassName,
  yPosKdClassNameOverride,
  textClassName3,
  xVelKpClassName,
  groupClassName3,
  xVelKpWrapperClassName,
  xVelKpClassNameOverride,
  textClassName4,
  yVelKpClassName,
  groupClassName4,
  yVelKpWrapperClassName,
  yVelKpClassNameOverride,
  textClassName5,
  xVelKiClassName,
  groupClassName5,
  xVelKiWrapperClassName,
  xVelKiClassNameOverride,
  textClassName6,
  yVelKiClassName,
  groupClassName6,
  yVelKiWrapperClassName,
  yVelKiClassNameOverride,
  textClassName7,
  xVelKdClassName,
  groupClassName7,
  xVelKdWrapperClassName,
  xVelKdClassNameOverride,
  textClassName8,
  yVelKdClassName,
  groupClassName8,
  yVelKdWrapperClassName,
  yVelKdClassNameOverride,
  textClassName9,
  xSetPointClassName,
  groupClassName9,
  xSetPointWrapperClassName,
  xSetPointClassNameOverride,
  textClassName10,
  ySetPointClassName,
  groupClassName10,
  ySetPointWrapperClassName,
  ySetPointClassNameOverride,
  pleaseEnterYourClassName,
}) => {
  return (
    <div className={`parameters ${className}`}>
      <div className={`text ${textClassName}`}>
        <div className={`text-wrapper-7 ${xPosKpClassName}`}>X Pos Kp</div>
        <div className={`group-11 ${groupClassName}`}>
          <input type="number" className={`input ${xPosKpClassNameOverride}`} />
        </div>
      </div>
      <div className={`text-2 ${textClassNameOverride}`}>
        <div className={`text-wrapper-7 ${yPosKpClassName}`}>Y Pos Kp</div>
        <div className={`group-11 ${groupClassNameOverride}`}>
          <input type="number" className={`input ${yPosKpClassNameOverride}`} />
        </div>
      </div>
      <div className={`text-3 ${divClassName}`}>
        <div className={`text-wrapper-7 ${xPosKiClassName}`}>X Pos Ki</div>
        <div className={`group-11 ${overlapGroupWrapperClassName}`}>
          <input type="number" className={`input ${xPosKiClassNameOverride}`} />
        </div>
      </div>
      <div className={`text-4 ${divClassNameOverride}`}>
        <div className={`text-wrapper-7 ${yPosKiClassName}`}>Y Pos Ki</div>
        <div className={`group-11 ${overlapGroupWrapperClassNameOverride}`}>
          <input type="number" className={`input ${yPosKiClassNameOverride}`} />
        </div>
      </div>
      <div className={`text-5 ${textClassName1}`}>
        <div className={`text-wrapper-7 ${xPosKdClassName}`}>X Pos Kd</div>
        <div className={`group-11 ${groupClassName1}`}>
          <input type="number" className={`input ${xPosKdClassNameOverride}`} />
        </div>
      </div>
      <div className={`text-6 ${textClassName2}`}>
        <div className={`text-wrapper-7 ${yPosKdClassName}`}>Y Pos Kd</div>
        <div className={`group-11 ${groupClassName2}`}>
          <input type="number" className={`input ${yPosKdClassNameOverride}`} />
        </div>
      </div>
      <div className={`text-7 ${textClassName3}`}>
        <div className={`text-wrapper-7 ${xVelKpClassName}`}>X Vel Kp</div>
        <div className={`group-11 ${groupClassName3}`}>
          <input type="number" className={`input ${xVelKpClassNameOverride}`} />
        </div>
      </div>
      <div className={`text-8 ${textClassName4}`}>
        <div className={`text-wrapper-7 ${yVelKpClassName}`}>Y Vel Kp</div>
        <div className={`group-11 ${groupClassName4}`}>
          <input type="number" className={`input ${yVelKpClassNameOverride}`} />
        </div>
      </div>
      <div className={`text-9 ${textClassName5}`}>
        <div className={`text-wrapper-7 ${xVelKiClassName}`}>X Vel Ki</div>
        <div className={`group-11 ${groupClassName5}`}>
          <input type="number" className={`input ${xVelKiClassNameOverride}`} />
        </div>
      </div>
      <div className={`text-10 ${textClassName6}`}>
        <div className={`text-wrapper-7 ${yVelKiClassName}`}>Y Vel Ki</div>
        <div className={`group-11 ${groupClassName6}`}>
          <input type="number" className={`input ${yVelKiClassNameOverride}`} />
        </div>
      </div>
      <div className={`text-11 ${textClassName7}`}>
        <div className={`text-wrapper-7 ${xVelKdClassName}`}>X Vel Kd</div>
        <div className={`group-11 ${groupClassName7}`}>
          <input type="number" className={`input ${xVelKdClassNameOverride}`} />
        </div>
      </div>
      <div className={`text-12 ${textClassName8}`}>
        <div className={`text-wrapper-7 ${yVelKdClassName}`}>Y Vel Kd</div>
        <div className={`group-11 ${groupClassName8}`}>
          <input type="number" className={`input ${yVelKdClassNameOverride}`} />
        </div>
      </div>
      <div className={`text-13 ${textClassName9}`}>
        <div className={`text-wrapper-7 ${xSetPointClassName}`}>X Set Point</div>
        <div className={`group-11 ${groupClassName9}`}>
          <input type="number" className={`input ${xSetPointClassNameOverride}`} />
        </div>
      </div>
      <div className={`text-14 ${textClassName10}`}>
        <div className={`text-wrapper-7 ${ySetPointClassName}`}>Y Set Point</div>
        <div className={`group-11 ${groupClassName10}`}>
          <input type="number" className={`input ${ySetPointClassNameOverride}`} />
        </div>
      </div>
      <p className={`please-enter-your ${pleaseEnterYourClassName}`}>Please Enter Your Parameters Below:</p>
    </div>
  );
};
