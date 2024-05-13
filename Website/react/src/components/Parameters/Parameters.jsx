/*
We're constantly improving the code you see. 
Please share your feedback here: https://form.asana.com/?k=uvp-HPgd3_hyoXRBw1IcNg&d=1152665201300829
*/

import React, {useState} from "react";
import "./style.css";

export const Parameters = ({
  className,
  textClassName,
  xPosKpClassName,
  xPosKpClassNameOverride,
  textClassNameOverride,
  yPosKpClassName,
  yPosKpClassNameOverride,
  divClassName,
  xPosKiClassName,
  xPosKiClassNameOverride,
  divClassNameOverride,
  yPosKiClassName,
  yPosKiClassNameOverride,
  textClassName1,
  xPosKdClassName,
  xPosKdClassNameOverride,
  textClassName2,
  yPosKdClassName,
  yPosKdClassNameOverride,
  textClassName3,
  xVelKpClassName,
  xVelKpClassNameOverride,
  textClassName4,
  yVelKpClassName,
  yVelKpClassNameOverride,
  textClassName5,
  xVelKiClassName,
  xVelKiClassNameOverride,
  textClassName6,
  yVelKiClassName,
  yVelKiClassNameOverride,
  textClassName7,
  xVelKdClassName,
  xVelKdClassNameOverride,
  textClassName8,
  yVelKdClassName,
  yVelKdClassNameOverride,
  textClassName9,
  xSetPointClassName,
  xSetPointClassNameOverride,
  textClassName10,
  ySetPointClassName,
  ySetPointClassNameOverride,
  pleaseEnterYourClassName,
  setParameterData,
}) => {
  const [xPosKp, setXPosKp] = useState("");
  const [yPosKp, setYPosKp] = useState("");
  const [xPosKi, setXPosKi] = useState("");
  const [yPosKi, setYPosKi] = useState("");
  const [xPosKd, setXPosKd] = useState("");
  const [yPosKd, setYPosKd] = useState("");
  const [xVelKp, setXVelKp] = useState("");
  const [yVelKp, setYVelKp] = useState("");
  const [xVelKi, setXVelKi] = useState("");
  const [yVelKi, setYVelKi] = useState("");
  const [xVelKd, setXVelKd] = useState("");
  const [yVelKd, setYVelKd] = useState("");
  const [xSetPoint, setXSetPoint] = useState("");
  const [ySetPoint, setYSetPoint] = useState("");

  // Function to update parameter data in the parent component
  const updateParameterData = () => {
    const data = {
      xPosKp,
      yPosKp,
      xPosKi,
      yPosKi,
      xPosKd,
      yPosKd,
      xVelKp,
      yVelKp,
      xVelKi,
      yVelKi,
      xVelKd,
      yVelKd,
      xSetPoint,
      ySetPoint,
    };
    setParameterData(data);
  };
  return (
    <div className={`parameters ${className}`}>
      <div className={`text ${textClassName}`}>
        <div className={`text-wrapper-7 ${xPosKpClassName}`}>X Pos Kp</div>
        <input type="number" className={`input ${xPosKpClassNameOverride}`} value={xPosKp} onChange={(e) => setXPosKp(e.target.value)} onBlur={updateParameterData}/>
      </div>
      <div className={`text-2 ${textClassNameOverride}`}>
        <div className={`text-wrapper-7 ${yPosKpClassName}`}>Y Pos Kp</div>
        <input type="number" className={`input ${yPosKpClassNameOverride}`} value={yPosKp} onChange={(e) => setYPosKp(e.target.value)} onBlur={updateParameterData}/>
      </div>
      <div className={`text-3 ${divClassName}`}>
        <div className={`text-wrapper-7 ${xPosKiClassName}`}>X Pos Ki</div>
        <input type="number" className={`input ${xPosKiClassNameOverride}`} value={xPosKi} onChange={(e) => setXPosKi(e.target.value)} onBlur={updateParameterData}/>
      </div>
      <div className={`text-4 ${divClassNameOverride}`}>
        <div className={`text-wrapper-7 ${yPosKiClassName}`}>Y Pos Ki</div>
        <input type="number" className={`input ${yPosKiClassNameOverride}`} value={yPosKi} onChange={(e) => setYPosKi(e.target.value)} onBlur={updateParameterData}/>
      </div>
      <div className={`text-5 ${textClassName1}`}>
        <div className={`text-wrapper-7 ${xPosKdClassName}`}>X Pos Kd</div>
        <input type="number" className={`input ${xPosKdClassNameOverride}`} value={xPosKd} onChange={(e) => setXPosKd(e.target.value)} onBlur={updateParameterData}/>
      </div>
      <div className={`text-6 ${textClassName2}`}>
        <div className={`text-wrapper-7 ${yPosKdClassName}`}>Y Pos Kd</div>
        <input type="number" className={`input ${yPosKdClassNameOverride}`} value={yPosKd} onChange={(e) => setYPosKd(e.target.value)} onBlur={updateParameterData}/>
      </div>
      <div className={`text-7 ${textClassName3}`}>
        <div className={`text-wrapper-7 ${xVelKpClassName}`}>X Vel Kp</div>
        <input type="number" className={`input ${xVelKpClassNameOverride}`} value={xVelKp} onChange={(e) => setXVelKp(e.target.value)} onBlur={updateParameterData}/>
      </div>
      <div className={`text-8 ${textClassName4}`}>
        <div className={`text-wrapper-7 ${yVelKpClassName}`}>Y Vel Kp</div>
        <input type="number" className={`input ${yVelKpClassNameOverride}`} value={yVelKp} onChange={(e) => setYVelKp(e.target.value)} onBlur={updateParameterData}/>
      </div>
      <div className={`text-9 ${textClassName5}`}>
        <div className={`text-wrapper-7 ${xVelKiClassName}`}>X Vel Ki</div>
        <input type="number" className={`input ${xVelKiClassNameOverride}`} value={xVelKi} onChange={(e) => setXVelKi(e.target.value)} onBlur={updateParameterData}/>
      </div>
      <div className={`text-10 ${textClassName6}`}>
        <div className={`text-wrapper-7 ${yVelKiClassName}`}>Y Vel Ki</div>
        <input type="number" className={`input ${yVelKiClassNameOverride}`} value={yVelKi} onChange={(e) => setYVelKi(e.target.value)} onBlur={updateParameterData}/>
      </div>
      <div className={`text-11 ${textClassName7}`}>
        <div className={`text-wrapper-7 ${xVelKdClassName}`}>X Vel Kd</div>
        <input type="number" className={`input ${xVelKdClassNameOverride}`} value={xVelKd} onChange={(e) => setXVelKd(e.target.value)} onBlur={updateParameterData} />
      </div>
      <div className={`text-12 ${textClassName8}`}>
        <div className={`text-wrapper-7 ${yVelKdClassName}`}>Y Vel Kd</div>
        <input type="number" className={`input ${yVelKdClassNameOverride}`} value={yVelKd} onChange={(e) => setYVelKd(e.target.value)} onBlur={updateParameterData}/>
      </div>
      <div className={`text-13 ${textClassName9}`}>
        <div className={`text-wrapper-7 ${xSetPointClassName}`}>X Set Point</div>
        <input type="number" className={`input ${xSetPointClassNameOverride}`} value={xSetPoint} onChange={(e) => setXSetPoint(e.target.value)} onBlur={updateParameterData}/>
      </div>
      <div className={`text-14 ${textClassName10}`}>
        <div className={`text-wrapper-7 ${ySetPointClassName}`}>Y Set Point</div>
        <input type="number" className={`input ${ySetPointClassNameOverride}`} value={ySetPoint} onChange={(e) => setYSetPoint(e.target.value)} onBlur={updateParameterData}/>
      </div>
      <p className={`please-enter-your ${pleaseEnterYourClassName}`}>Please Enter Your Parameters Below:</p>
    </div>
  );
};
