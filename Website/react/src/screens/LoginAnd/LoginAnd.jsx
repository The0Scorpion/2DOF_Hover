import React from "react";
import { useWindowWidth } from "../../breakpoints";
import { LoginBar } from "../../components/LoginBar";
import { NavLogWrapper } from "../../components/NavLogWrapper";
import "./style.css";

export const LoginAnd = () => {
  const screenWidth = useWindowWidth();

  return (
    <div className="login-and">
      <div
        className="div-2"
        style={{
          background: "linear-gradient(180deg, rgb(5, 5, 24) 0%, rgb(26.25, 26.25, 126) 100%)",
          height:
            screenWidth < 834
              ? "720px"
              : screenWidth >= 834 && screenWidth < 1440
                ? "1300px"
                : screenWidth >= 1440
                  ? "1950px"
                  : undefined,
          width:
            screenWidth < 834
              ? "360px"
              : screenWidth >= 834 && screenWidth < 1440
                ? "834px"
                : screenWidth >= 1440
                  ? "1540px"
                  : undefined,
        }}
      >
        {screenWidth < 834 && (
          <>
          <LoginBar
              className="login-bar-instance-1"
              logInClassName="instance-node-1"
              logInClassNameOverride="login-bar-10-1"
              loginButtonClassName="login-bar-8-1"
              overlapClassName="login-bar-3-1"
              overlapClassNameOverride="login-bar-5-1"
              overlapGroupClassName="login-bar-9-1"
              passwordClassName="login-bar-7-1"
              rectangleClassName="login-bar-6-1"
              usernameEmailComClassName="login-bar-4-1"
              createButtonClassName="createbutton-1"
              createoverlapGroupClassName="createlap-1"
              createClassNameOverride="createclassname-1"
          />
          <NavLogWrapper 
              className="navlog834"
              maskgroup="maskgroup"/>
          </>
        )}

        {(screenWidth >= 1440 || (screenWidth >= 834 && screenWidth < 1440)) && (
          <div
            className="overlap-4"
            style={{
              height: screenWidth >= 834 && screenWidth < 1440 ? "656px" : screenWidth >= 1440 ? "746px" : undefined,
              left: screenWidth >= 834 && screenWidth < 1440 ? "23px" : screenWidth >= 1440 ? "123px" : undefined,
              top: screenWidth >= 834 && screenWidth < 1440 ? "196px" : screenWidth >= 1440 ? "165px" : undefined,
              width: screenWidth >= 834 && screenWidth < 1440 ? "793px" : screenWidth >= 1440 ? "1217px" : undefined,
            }}
          >
            {screenWidth >= 834 && screenWidth < 1440 && (
              <>
                <LoginBar
                  className="login-bar-instance"
                  logInClassName="instance-node"
                  logInClassNameOverride="login-bar-10"
                  loginButtonClassName="login-bar-8"
                  overlapClassName="login-bar-3"
                  overlapClassNameOverride="login-bar-5"
                  overlapGroupClassName="login-bar-9"
                  passwordClassName="login-bar-7"
                  rectangleClassName="login-bar-6"
                  usernameEmailComClassName="login-bar-4"
                  createButtonClassName="createbutton"
                  createoverlapGroupClassName="createlap"
                  createClassNameOverride="createclassname"
                />
                <NavLogWrapper className="nav-log-1" />
              </>
            )}

            {screenWidth >= 1440 && (
              <>
                <LoginBar className="login-bar-11" />
                <NavLogWrapper className="nav-log-instance" />
              </>
            )}
          </div>
        )}
      </div>
    </div>
  );
};
