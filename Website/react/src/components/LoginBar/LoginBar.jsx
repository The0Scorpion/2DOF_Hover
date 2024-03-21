/*
We're constantly improving the code you see. 
Please share your feedback here: https://form.asana.com/?k=uvp-HPgd3_hyoXRBw1IcNg&d=1152665201300829
*/

import React from "react";
import "./style.css";

export const LoginBar = ({
  className,
  logInClassName,
  overlapClassName,
  usernameEmailComClassName,
  overlapClassNameOverride,
  rectangleClassName,
  passwordClassName,
  loginButtonClassName,
  overlapGroupClassName,
  logInClassNameOverride,
  createButtonClassName,
    createoverlapGroupClassName,
    createClassNameOverride,

}) => {
  return (
    <div className={`login-bar ${className}`}>
      <div className={`log-in ${logInClassName}`}>Log In</div>
      <input type="email" placeholder="username@email.com" className={`username-email-com ${usernameEmailComClassName}`} />
      <input type="password" placeholder="Password" className={`password ${passwordClassName}`} />
      <div className={`login-button ${loginButtonClassName}`}>
        <button className={`log-in-wrapper ${overlapGroupClassName}`}>
          <div className={`text-wrapper ${logInClassNameOverride}`}>Log In</div>
        </button>
      </div>
      <div className={`create-button ${createButtonClassName}`}>
        <button className={`create-wrapper ${createoverlapGroupClassName}`}>
          <div className={`text-create-wrapper ${createClassNameOverride}`}>Create New Accout</div>
        </button>
      </div>
    </div>
  );
};
