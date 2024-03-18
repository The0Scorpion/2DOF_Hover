import React from "react";
import { useWindowWidth } from "../../breakpoints";
import { Blur } from "../../components/Blur";
import { Buttons } from "../../components/Buttons";
import { Footer } from "../../components/Footer";
import { Graphs } from "../../components/Graphs";
import { NavBar } from "../../components/NavBar";
import { Parameters } from "../../components/Parameters";
import { SimulationStreaming } from "../../components/SimulationStreaming";
import { VideoStream } from "../../components/VideoStream";
import "./style.css";

export const AndroidLarge = () => {
  const screenWidth = useWindowWidth();

  return (
    <div className="android-large">
      <div
        className="overlap-wrapper-2"
        style={{
          height:
            screenWidth < 834
              ? "2650px"
              : screenWidth >= 834 && screenWidth < 1440
              ? "2937px"
              : screenWidth >= 1440
              ? "3459px"
              : undefined,
          width:
            screenWidth < 834
              ? "360px"
              : screenWidth >= 834 && screenWidth < 1440
              ? "834px"
              : screenWidth >= 1440
              ? "1440px"
              : undefined,
        }}
      >
        <div
          className="overlap-6"
          style={{
            height:
              screenWidth < 834
                ? "3926px"
                : screenWidth >= 834 && screenWidth < 1440
                ? "4061px"
                : screenWidth >= 1440
                ? "3663px"
                : undefined,
            left:
              screenWidth < 834
                ? "-256px"
                : screenWidth >= 834 && screenWidth < 1440
                ? "-181px"
                : screenWidth >= 1440
                ? "-705px"
                : undefined,
            top:
              screenWidth < 834
                ? "-467px"
                : screenWidth >= 834 && screenWidth < 1440
                ? "-790px"
                : screenWidth >= 1440
                ? "-204px"
                : undefined,
            width:
              screenWidth < 834
                ? "724px"
                : screenWidth >= 834 && screenWidth < 1440
                ? "1098px"
                : screenWidth >= 1440
                ? "2431px"
                : undefined,
          }}
        >
          {((screenWidth >= 834 && screenWidth < 1440) || screenWidth < 834) && (
            <>
              <Blur
                className={`${screenWidth >= 834 && screenWidth < 1440 && "class-3"} ${screenWidth < 834 && "class-4"}`}
                divClassName={`${screenWidth >= 834 && screenWidth < 1440 && "class-7"} ${
                  screenWidth < 834 && "class-8"
                }`}
                ellipseClassName={`${screenWidth >= 834 && screenWidth < 1440 && "class-5"} ${
                  screenWidth < 834 && "class-6"
                }`}
                ellipseClassNameOverride={`${screenWidth >= 834 && screenWidth < 1440 && "class"} ${
                  screenWidth < 834 && "class-2"
                }`}
              />
              <footer
                className="footer-2"
                style={{
                  height: screenWidth < 834 ? "77px" : screenWidth >= 834 && screenWidth < 1440 ? "141px" : undefined,
                  left: screenWidth < 834 ? "202px" : screenWidth >= 834 && screenWidth < 1440 ? "181px" : undefined,
                  top: screenWidth < 834 ? "3037px" : screenWidth >= 834 && screenWidth < 1440 ? "3584px" : undefined,
                  width: screenWidth < 834 ? "468px" : screenWidth >= 834 && screenWidth < 1440 ? "834px" : undefined,
                }}
              >
                <div
                  className="group-30"
                  style={{
                    height: screenWidth < 834 ? "64px" : screenWidth >= 834 && screenWidth < 1440 ? "117px" : undefined,
                    left: screenWidth < 834 ? "61px" : screenWidth >= 834 && screenWidth < 1440 ? "108px" : undefined,
                    width: screenWidth < 834 ? "346px" : screenWidth >= 834 && screenWidth < 1440 ? "617px" : undefined,
                  }}
                >
                  <div
                    className="group-31"
                    style={{
                      height:
                        screenWidth < 834 ? "53px" : screenWidth >= 834 && screenWidth < 1440 ? "96px" : undefined,
                      left: screenWidth < 834 ? "10px" : screenWidth >= 834 && screenWidth < 1440 ? "19px" : undefined,
                      top: screenWidth < 834 ? "4px" : screenWidth >= 834 && screenWidth < 1440 ? "9px" : undefined,
                      width:
                        screenWidth < 834 ? "326px" : screenWidth >= 834 && screenWidth < 1440 ? "582px" : undefined,
                    }}
                  >
                    <div
                      className="control-chef-high-2"
                      style={{
                        height:
                          screenWidth < 834 ? "17px" : screenWidth >= 834 && screenWidth < 1440 ? "32px" : undefined,
                        top: screenWidth < 834 ? "19px" : screenWidth >= 834 && screenWidth < 1440 ? "34px" : undefined,
                        width:
                          screenWidth < 834 ? "103px" : screenWidth >= 834 && screenWidth < 1440 ? "184px" : undefined,
                      }}
                    >
                      <div
                        className="group-52"
                        style={{
                          height:
                            screenWidth < 834 ? "17px" : screenWidth >= 834 && screenWidth < 1440 ? "32px" : undefined,
                        }}
                      >
                        <div
                          className="frame-5"
                          style={{
                            height:
                              screenWidth < 834
                                ? "17px"
                                : screenWidth >= 834 && screenWidth < 1440
                                ? "32px"
                                : undefined,
                            width:
                              screenWidth < 834
                                ? "103px"
                                : screenWidth >= 834 && screenWidth < 1440
                                ? "184px"
                                : undefined,
                          }}
                        >
                          <div
                            className="tight-bounds"
                            style={{
                              height:
                                screenWidth < 834
                                  ? "17px"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "32px"
                                  : undefined,
                              width: screenWidth >= 834 && screenWidth < 1440 ? "183px" : undefined,
                            }}
                          >
                            <div
                              className="frame-14"
                              style={{
                                height:
                                  screenWidth < 834
                                    ? "17px"
                                    : screenWidth >= 834 && screenWidth < 1440
                                    ? "32px"
                                    : undefined,
                                width: screenWidth < 834 ? "103px" : undefined,
                              }}
                            >
                              <div
                                className="overlap-7"
                                style={{
                                  height:
                                    screenWidth < 834
                                      ? "17px"
                                      : screenWidth >= 834 && screenWidth < 1440
                                      ? "32px"
                                      : undefined,
                                  width: screenWidth >= 834 && screenWidth < 1440 ? "183px" : undefined,
                                }}
                              >
                                <div
                                  className="frame-wrapper"
                                  style={{
                                    height:
                                      screenWidth < 834
                                        ? "17px"
                                        : screenWidth >= 834 && screenWidth < 1440
                                        ? "32px"
                                        : undefined,
                                    width:
                                      screenWidth < 834
                                        ? "103px"
                                        : screenWidth >= 834 && screenWidth < 1440
                                        ? "183px"
                                        : undefined,
                                  }}
                                >
                                  <div
                                    className="frame-14"
                                    style={{
                                      height:
                                        screenWidth < 834
                                          ? "17px"
                                          : screenWidth >= 834 && screenWidth < 1440
                                          ? "32px"
                                          : undefined,
                                    }}
                                  >
                                    <div
                                      className="group-52"
                                      style={{
                                        height:
                                          screenWidth < 834
                                            ? "17px"
                                            : screenWidth >= 834 && screenWidth < 1440
                                            ? "32px"
                                            : undefined,
                                        width:
                                          screenWidth < 834
                                            ? "103px"
                                            : screenWidth >= 834 && screenWidth < 1440
                                            ? "183px"
                                            : undefined,
                                      }}
                                    >
                                      <div
                                        className="textblocktransform-wrapper"
                                        style={{
                                          height:
                                            screenWidth < 834
                                              ? "17px"
                                              : screenWidth >= 834 && screenWidth < 1440
                                              ? "32px"
                                              : undefined,
                                        }}
                                      >
                                        <div
                                          className="textblocktransform"
                                          style={{
                                            height:
                                              screenWidth < 834
                                                ? "17px"
                                                : screenWidth >= 834 && screenWidth < 1440
                                                ? "32px"
                                                : undefined,
                                            width:
                                              screenWidth < 834
                                                ? "103px"
                                                : screenWidth >= 834 && screenWidth < 1440
                                                ? "183px"
                                                : undefined,
                                          }}
                                        >
                                          <div
                                            className="textblock"
                                            style={{
                                              height:
                                                screenWidth < 834
                                                  ? "17px"
                                                  : screenWidth >= 834 && screenWidth < 1440
                                                  ? "32px"
                                                  : undefined,
                                            }}
                                          >
                                            <div
                                              className="group-52"
                                              style={{
                                                height:
                                                  screenWidth < 834
                                                    ? "17px"
                                                    : screenWidth >= 834 && screenWidth < 1440
                                                    ? "32px"
                                                    : undefined,
                                                width:
                                                  screenWidth < 834
                                                    ? "103px"
                                                    : screenWidth >= 834 && screenWidth < 1440
                                                    ? "183px"
                                                    : undefined,
                                              }}
                                            >
                                              <div
                                                className="frame-6"
                                                style={{
                                                  height:
                                                    screenWidth < 834
                                                      ? "17px"
                                                      : screenWidth >= 834 && screenWidth < 1440
                                                      ? "32px"
                                                      : undefined,
                                                }}
                                              >
                                                <div
                                                  className="overlap-group-4"
                                                  style={{
                                                    height:
                                                      screenWidth < 834
                                                        ? "30px"
                                                        : screenWidth >= 834 && screenWidth < 1440
                                                        ? "54px"
                                                        : undefined,
                                                    width:
                                                      screenWidth < 834
                                                        ? "103px"
                                                        : screenWidth >= 834 && screenWidth < 1440
                                                        ? "183px"
                                                        : undefined,
                                                  }}
                                                >
                                                  <div
                                                    className="group-32"
                                                    style={{
                                                      height:
                                                        screenWidth < 834
                                                          ? "30px"
                                                          : screenWidth >= 834 && screenWidth < 1440
                                                          ? "54px"
                                                          : undefined,
                                                      width:
                                                        screenWidth < 834
                                                          ? "31px"
                                                          : screenWidth >= 834 && screenWidth < 1440
                                                          ? "55px"
                                                          : undefined,
                                                    }}
                                                  />
                                                  <div
                                                    className="group-33"
                                                    style={{
                                                      height:
                                                        screenWidth < 834
                                                          ? "30px"
                                                          : screenWidth >= 834 && screenWidth < 1440
                                                          ? "54px"
                                                          : undefined,
                                                      width:
                                                        screenWidth < 834
                                                          ? "31px"
                                                          : screenWidth >= 834 && screenWidth < 1440
                                                          ? "55px"
                                                          : undefined,
                                                    }}
                                                  />
                                                  <div
                                                    className="text-15"
                                                    style={{
                                                      height:
                                                        screenWidth < 834
                                                          ? "17px"
                                                          : screenWidth >= 834 && screenWidth < 1440
                                                          ? "32px"
                                                          : undefined,
                                                      width:
                                                        screenWidth < 834
                                                          ? "103px"
                                                          : screenWidth >= 834 && screenWidth < 1440
                                                          ? "183px"
                                                          : undefined,
                                                    }}
                                                  >
                                                    <div
                                                      className="frame-7"
                                                      style={{
                                                        height:
                                                          screenWidth < 834
                                                            ? "17px"
                                                            : screenWidth >= 834 && screenWidth < 1440
                                                            ? "32px"
                                                            : undefined,
                                                      }}
                                                    >
                                                      <div
                                                        className="group-34"
                                                        style={{
                                                          height:
                                                            screenWidth < 834
                                                              ? "11px"
                                                              : screenWidth >= 834 && screenWidth < 1440
                                                              ? "19px"
                                                              : undefined,
                                                          top:
                                                            screenWidth < 834
                                                              ? "3px"
                                                              : screenWidth >= 834 && screenWidth < 1440
                                                              ? "6px"
                                                              : undefined,
                                                          width:
                                                            screenWidth < 834
                                                              ? "49px"
                                                              : screenWidth >= 834 && screenWidth < 1440
                                                              ? "87px"
                                                              : undefined,
                                                        }}
                                                      />
                                                      <div
                                                        className="group-35"
                                                        style={{
                                                          height:
                                                            screenWidth < 834
                                                              ? "17px"
                                                              : screenWidth >= 834 && screenWidth < 1440
                                                              ? "32px"
                                                              : undefined,
                                                          left:
                                                            screenWidth < 834
                                                              ? "53px"
                                                              : screenWidth >= 834 && screenWidth < 1440
                                                              ? "95px"
                                                              : undefined,
                                                          width:
                                                            screenWidth < 834
                                                              ? "15px"
                                                              : screenWidth >= 834 && screenWidth < 1440
                                                              ? "27px"
                                                              : undefined,
                                                        }}
                                                      />
                                                      <div
                                                        className="group-36"
                                                        style={{
                                                          height:
                                                            screenWidth < 834
                                                              ? "11px"
                                                              : screenWidth >= 834 && screenWidth < 1440
                                                              ? "20px"
                                                              : undefined,
                                                          left:
                                                            screenWidth < 834
                                                              ? "73px"
                                                              : screenWidth >= 834 && screenWidth < 1440
                                                              ? "130px"
                                                              : undefined,
                                                          top:
                                                            screenWidth < 834
                                                              ? "3px"
                                                              : screenWidth >= 834 && screenWidth < 1440
                                                              ? "6px"
                                                              : undefined,
                                                          width:
                                                            screenWidth < 834
                                                              ? "30px"
                                                              : screenWidth >= 834 && screenWidth < 1440
                                                              ? "53px"
                                                              : undefined,
                                                        }}
                                                      />
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
                                <img
                                  className="mask-group-4"
                                  style={{
                                    height:
                                      screenWidth < 834
                                        ? "17px"
                                        : screenWidth >= 834 && screenWidth < 1440
                                        ? "32px"
                                        : undefined,
                                    width:
                                      screenWidth < 834
                                        ? "103px"
                                        : screenWidth >= 834 && screenWidth < 1440
                                        ? "183px"
                                        : undefined,
                                  }}
                                  alt="Mask group"
                                  src={
                                    screenWidth < 834
                                      ? "https://c.animaapp.com/zqIJEW6i/img/mask-group-7@2x.png"
                                      : screenWidth >= 834 && screenWidth < 1440
                                      ? "https://c.animaapp.com/zqIJEW6i/img/mask-group-13@2x.png"
                                      : undefined
                                  }
                                />
                                <img
                                  className="mask-group-5"
                                  style={{
                                    height:
                                      screenWidth < 834
                                        ? "17px"
                                        : screenWidth >= 834 && screenWidth < 1440
                                        ? "32px"
                                        : undefined,
                                    width:
                                      screenWidth < 834
                                        ? "103px"
                                        : screenWidth >= 834 && screenWidth < 1440
                                        ? "183px"
                                        : undefined,
                                  }}
                                  alt="Mask group"
                                  src={
                                    screenWidth < 834
                                      ? "https://c.animaapp.com/zqIJEW6i/img/mask-group-8@2x.png"
                                      : screenWidth >= 834 && screenWidth < 1440
                                      ? "https://c.animaapp.com/zqIJEW6i/img/mask-group-14@2x.png"
                                      : undefined
                                  }
                                />
                                <img
                                  className="mask-group-6"
                                  style={{
                                    height:
                                      screenWidth < 834
                                        ? "17px"
                                        : screenWidth >= 834 && screenWidth < 1440
                                        ? "32px"
                                        : undefined,
                                    width:
                                      screenWidth < 834
                                        ? "103px"
                                        : screenWidth >= 834 && screenWidth < 1440
                                        ? "183px"
                                        : undefined,
                                  }}
                                  alt="Mask group"
                                  src={
                                    screenWidth < 834
                                      ? "https://c.animaapp.com/zqIJEW6i/img/mask-group-9@2x.png"
                                      : screenWidth >= 834 && screenWidth < 1440
                                      ? "https://c.animaapp.com/zqIJEW6i/img/mask-group-15@2x.png"
                                      : undefined
                                  }
                                />
                              </div>
                            </div>
                          </div>
                        </div>
                      </div>
                    </div>
                    <div
                      className="group-37"
                      style={{
                        height:
                          screenWidth < 834 ? "53px" : screenWidth >= 834 && screenWidth < 1440 ? "96px" : undefined,
                        left:
                          screenWidth < 834 ? "287px" : screenWidth >= 834 && screenWidth < 1440 ? "512px" : undefined,
                        width:
                          screenWidth < 834 ? "41px" : screenWidth >= 834 && screenWidth < 1440 ? "72px" : undefined,
                      }}
                    >
                      <div
                        className="text-wrapper-15"
                        style={{
                          fontSize:
                            screenWidth < 834 ? "10px" : screenWidth >= 834 && screenWidth < 1440 ? "18px" : undefined,
                          height:
                            screenWidth < 834 ? "12px" : screenWidth >= 834 && screenWidth < 1440 ? "22px" : undefined,
                          whiteSpace: screenWidth < 834 ? "nowrap" : undefined,
                        }}
                      >
                        Contact
                      </div>
                      <div
                        className="group-38"
                        style={{
                          height:
                            screenWidth < 834 ? "39px" : screenWidth >= 834 && screenWidth < 1440 ? "70px" : undefined,
                          left:
                            screenWidth < 834 ? "5px" : screenWidth >= 834 && screenWidth < 1440 ? "7px" : undefined,
                          top:
                            screenWidth < 834 ? "14px" : screenWidth >= 834 && screenWidth < 1440 ? "26px" : undefined,
                          width:
                            screenWidth < 834 ? "42px" : screenWidth >= 834 && screenWidth < 1440 ? "71px" : undefined,
                        }}
                      >
                        <div
                          className="overlap-group-5"
                          style={{
                            height:
                              screenWidth < 834
                                ? "39px"
                                : screenWidth >= 834 && screenWidth < 1440
                                ? "70px"
                                : undefined,
                            width:
                              screenWidth < 834
                                ? "34px"
                                : screenWidth >= 834 && screenWidth < 1440
                                ? "63px"
                                : undefined,
                          }}
                        >
                          <div
                            className="text-wrapper-16"
                            style={{
                              fontFamily:
                                screenWidth < 834
                                  ? "'Salsa', Helvetica"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-font-family)"
                                  : undefined,
                              fontSize:
                                screenWidth < 834
                                  ? "8px"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-font-size)"
                                  : undefined,
                              fontStyle:
                                screenWidth >= 834 && screenWidth < 1440 ? "var(--paragraph-font-style)" : undefined,
                              fontWeight:
                                screenWidth < 834
                                  ? "400"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-font-weight)"
                                  : undefined,
                              height:
                                screenWidth < 834
                                  ? "10px"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "18px"
                                  : undefined,
                              left:
                                screenWidth < 834
                                  ? "3px"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "5px"
                                  : undefined,
                              letterSpacing:
                                screenWidth < 834
                                  ? "0"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-letter-spacing)"
                                  : undefined,
                              lineHeight:
                                screenWidth < 834
                                  ? "normal"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-line-height)"
                                  : undefined,
                              whiteSpace: screenWidth >= 834 && screenWidth < 1440 ? "nowrap" : undefined,
                            }}
                          >
                            Email
                          </div>
                          <div
                            className="text-wrapper-17"
                            style={{
                              fontFamily:
                                screenWidth < 834
                                  ? "'Salsa', Helvetica"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-font-family)"
                                  : undefined,
                              fontSize:
                                screenWidth < 834
                                  ? "8px"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-font-size)"
                                  : undefined,
                              fontStyle:
                                screenWidth >= 834 && screenWidth < 1440 ? "var(--paragraph-font-style)" : undefined,
                              fontWeight:
                                screenWidth < 834
                                  ? "400"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-font-weight)"
                                  : undefined,
                              height:
                                screenWidth < 834
                                  ? "10px"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "18px"
                                  : undefined,
                              letterSpacing:
                                screenWidth < 834
                                  ? "0"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-letter-spacing)"
                                  : undefined,
                              lineHeight:
                                screenWidth < 834
                                  ? "normal"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-line-height)"
                                  : undefined,
                              top:
                                screenWidth < 834
                                  ? "10px"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "17px"
                                  : undefined,
                              whiteSpace: screenWidth >= 834 && screenWidth < 1440 ? "nowrap" : undefined,
                            }}
                          >
                            Linkedin
                          </div>
                          <div
                            className="text-wrapper-18"
                            style={{
                              fontFamily:
                                screenWidth < 834
                                  ? "'Salsa', Helvetica"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-font-family)"
                                  : undefined,
                              fontSize:
                                screenWidth < 834
                                  ? "8px"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-font-size)"
                                  : undefined,
                              fontStyle:
                                screenWidth >= 834 && screenWidth < 1440 ? "var(--paragraph-font-style)" : undefined,
                              fontWeight:
                                screenWidth < 834
                                  ? "400"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-font-weight)"
                                  : undefined,
                              height:
                                screenWidth < 834
                                  ? "10px"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "18px"
                                  : undefined,
                              letterSpacing:
                                screenWidth < 834
                                  ? "0"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-letter-spacing)"
                                  : undefined,
                              lineHeight:
                                screenWidth < 834
                                  ? "normal"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-line-height)"
                                  : undefined,
                              top:
                                screenWidth < 834
                                  ? "19px"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "35px"
                                  : undefined,
                              whiteSpace: screenWidth >= 834 && screenWidth < 1440 ? "nowrap" : undefined,
                            }}
                          >
                            Instgram
                          </div>
                          <div
                            className="text-wrapper-19"
                            style={{
                              fontFamily:
                                screenWidth < 834
                                  ? "'Salsa', Helvetica"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-font-family)"
                                  : undefined,
                              fontSize:
                                screenWidth < 834
                                  ? "8px"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-font-size)"
                                  : undefined,
                              fontStyle:
                                screenWidth >= 834 && screenWidth < 1440 ? "var(--paragraph-font-style)" : undefined,
                              fontWeight:
                                screenWidth < 834
                                  ? "400"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-font-weight)"
                                  : undefined,
                              height:
                                screenWidth < 834
                                  ? "10px"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "18px"
                                  : undefined,
                              letterSpacing:
                                screenWidth < 834
                                  ? "0"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-letter-spacing)"
                                  : undefined,
                              lineHeight:
                                screenWidth < 834
                                  ? "normal"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-line-height)"
                                  : undefined,
                              top:
                                screenWidth < 834
                                  ? "29px"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "52px"
                                  : undefined,
                              whiteSpace: screenWidth >= 834 && screenWidth < 1440 ? "nowrap" : undefined,
                            }}
                          >
                            Facebook
                          </div>
                        </div>
                      </div>
                    </div>
                    <div
                      className="group-39"
                      style={{
                        height:
                          screenWidth < 834 ? "34px" : screenWidth >= 834 && screenWidth < 1440 ? "62px" : undefined,
                        left:
                          screenWidth < 834 ? "222px" : screenWidth >= 834 && screenWidth < 1440 ? "396px" : undefined,
                        width:
                          screenWidth < 834 ? "59px" : screenWidth >= 834 && screenWidth < 1440 ? "105px" : undefined,
                      }}
                    >
                      <div
                        className="control-chef"
                        style={{
                          fontSize:
                            screenWidth < 834 ? "10px" : screenWidth >= 834 && screenWidth < 1440 ? "18px" : undefined,
                          height:
                            screenWidth < 834 ? "12px" : screenWidth >= 834 && screenWidth < 1440 ? "22px" : undefined,
                          whiteSpace: screenWidth < 834 ? "nowrap" : undefined,
                        }}
                      >
                        Control Chef
                      </div>
                      <div
                        className="group-40"
                        style={{
                          height:
                            screenWidth < 834 ? "20px" : screenWidth >= 834 && screenWidth < 1440 ? "35px" : undefined,
                          left:
                            screenWidth < 834 ? "15px" : screenWidth >= 834 && screenWidth < 1440 ? "26px" : undefined,
                          top:
                            screenWidth < 834 ? "14px" : screenWidth >= 834 && screenWidth < 1440 ? "26px" : undefined,
                          width:
                            screenWidth < 834 ? "37px" : screenWidth >= 834 && screenWidth < 1440 ? "65px" : undefined,
                        }}
                      >
                        <div
                          className="overlap-group-6"
                          style={{
                            height:
                              screenWidth < 834
                                ? "20px"
                                : screenWidth >= 834 && screenWidth < 1440
                                ? "35px"
                                : undefined,
                            width:
                              screenWidth < 834
                                ? "33px"
                                : screenWidth >= 834 && screenWidth < 1440
                                ? "61px"
                                : undefined,
                          }}
                        >
                          <div
                            className="home"
                            style={{
                              fontFamily:
                                screenWidth < 834
                                  ? "'Salsa', Helvetica"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-font-family)"
                                  : undefined,
                              fontSize:
                                screenWidth < 834
                                  ? "8px"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-font-size)"
                                  : undefined,
                              fontStyle:
                                screenWidth >= 834 && screenWidth < 1440 ? "var(--paragraph-font-style)" : undefined,
                              fontWeight:
                                screenWidth < 834
                                  ? "400"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-font-weight)"
                                  : undefined,
                              height:
                                screenWidth < 834
                                  ? "10px"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "18px"
                                  : undefined,
                              left:
                                screenWidth < 834
                                  ? "3px"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "5px"
                                  : undefined,
                              letterSpacing:
                                screenWidth < 834
                                  ? "0"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-letter-spacing)"
                                  : undefined,
                              lineHeight:
                                screenWidth < 834
                                  ? "normal"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-line-height)"
                                  : undefined,
                              whiteSpace: screenWidth >= 834 && screenWidth < 1440 ? "nowrap" : undefined,
                            }}
                          >
                            Home
                          </div>
                          <div
                            className="about-us"
                            style={{
                              fontFamily:
                                screenWidth < 834
                                  ? "'Salsa', Helvetica"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-font-family)"
                                  : undefined,
                              fontSize:
                                screenWidth < 834
                                  ? "8px"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-font-size)"
                                  : undefined,
                              fontStyle:
                                screenWidth >= 834 && screenWidth < 1440 ? "var(--paragraph-font-style)" : undefined,
                              fontWeight:
                                screenWidth < 834
                                  ? "400"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-font-weight)"
                                  : undefined,
                              height:
                                screenWidth < 834
                                  ? "10px"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "18px"
                                  : undefined,
                              letterSpacing:
                                screenWidth < 834
                                  ? "0"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-letter-spacing)"
                                  : undefined,
                              lineHeight:
                                screenWidth < 834
                                  ? "normal"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "var(--paragraph-line-height)"
                                  : undefined,
                              top:
                                screenWidth < 834
                                  ? "10px"
                                  : screenWidth >= 834 && screenWidth < 1440
                                  ? "17px"
                                  : undefined,
                              whiteSpace: screenWidth >= 834 && screenWidth < 1440 ? "nowrap" : undefined,
                            }}
                          >
                            About Us
                          </div>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
                <div
                  className="group-41"
                  style={{
                    height: screenWidth < 834 ? "7px" : screenWidth >= 834 && screenWidth < 1440 ? "12px" : undefined,
                    top: screenWidth < 834 ? "71px" : screenWidth >= 834 && screenWidth < 1440 ? "129px" : undefined,
                    width: screenWidth < 834 ? "470px" : screenWidth >= 834 && screenWidth < 1440 ? "836px" : undefined,
                  }}
                >
                  <div
                    className="overlap-8"
                    style={{
                      height: screenWidth < 834 ? "7px" : screenWidth >= 834 && screenWidth < 1440 ? "12px" : undefined,
                      width:
                        screenWidth < 834 ? "468px" : screenWidth >= 834 && screenWidth < 1440 ? "834px" : undefined,
                    }}
                  >
                    <div
                      className="rectangle-7"
                      style={{
                        height:
                          screenWidth < 834 ? "6px" : screenWidth >= 834 && screenWidth < 1440 ? "10px" : undefined,
                        width:
                          screenWidth < 834 ? "468px" : screenWidth >= 834 && screenWidth < 1440 ? "834px" : undefined,
                      }}
                    />
                    <p
                      className="p"
                      style={{
                        fontFamily:
                          screenWidth < 834
                            ? "'Salsa', Helvetica"
                            : screenWidth >= 834 && screenWidth < 1440
                            ? "var(--copyright-font-family)"
                            : undefined,
                        fontSize:
                          screenWidth < 834
                            ? "6px"
                            : screenWidth >= 834 && screenWidth < 1440
                            ? "var(--copyright-font-size)"
                            : undefined,
                        fontStyle: screenWidth >= 834 && screenWidth < 1440 ? "var(--copyright-font-style)" : undefined,
                        fontWeight:
                          screenWidth < 834
                            ? "400"
                            : screenWidth >= 834 && screenWidth < 1440
                            ? "var(--copyright-font-weight)"
                            : undefined,
                        height:
                          screenWidth < 834 ? "7px" : screenWidth >= 834 && screenWidth < 1440 ? "12px" : undefined,
                        left:
                          screenWidth < 834 ? "46px" : screenWidth >= 834 && screenWidth < 1440 ? "229px" : undefined,
                        letterSpacing:
                          screenWidth < 834
                            ? "0"
                            : screenWidth >= 834 && screenWidth < 1440
                            ? "var(--copyright-letter-spacing)"
                            : undefined,
                        lineHeight:
                          screenWidth < 834
                            ? "normal"
                            : screenWidth >= 834 && screenWidth < 1440
                            ? "var(--copyright-line-height)"
                            : undefined,
                      }}
                    >
                      Copyright @ 2024 Control Chef - All Rights Reserved
                    </p>
                  </div>
                </div>
              </footer>
            </>
          )}

          {screenWidth >= 834 && screenWidth < 1440 && (
            <Graphs
              className="graphs-instance"
              divClassName="graphs-5"
              divClassName1="graphs-16"
              divClassNameOverride="graphs-6"
              groupClassName="instance-node"
              groupClassName1="graphs-8"
              groupClassName2="graphs-9"
              groupClassName3="graphs-11"
              groupClassName4="graphs-12"
              groupClassName5="graphs-14"
              groupClassNameOverride="graphs-4"
              rectangleClassName="graphs-2"
              rectangleClassName1="graphs-2"
              rectangleClassName2="graphs-6"
              rectangleClassName3="graphs-6"
              rectangleClassName4="graphs-6"
              rectangleClassName5="graphs-6"
              rectangleClassNameOverride="graphs-2"
              xPosClassName="graphs-3"
              xPosPidClassName="graphs-10"
              xVelClassName="graphs-7"
              xVelPidClassName="graphs-13"
              yPosClassName="graphs-3"
              yPosPidClassName="graphs-10"
              yVelClassName="graphs-3"
              yVelPidClassName="graphs-15"
            />
          )}

          {((screenWidth >= 834 && screenWidth < 1440) || screenWidth < 834) && (
            <VideoStream
              className={`${screenWidth < 834 && "class-9"} ${screenWidth >= 834 && screenWidth < 1440 && "class-10"}`}
              videoStream={
                screenWidth < 834
                  ? "https://c.animaapp.com/zqIJEW6i/img/video-stream-1.svg"
                  : screenWidth >= 834 && screenWidth < 1440
                  ? "https://c.animaapp.com/zqIJEW6i/img/video-stream-2.svg"
                  : undefined
              }
              videoStreamClassName={`${screenWidth < 834 && "class-13"} ${
                screenWidth >= 834 && screenWidth < 1440 && "class-14"
              }`}
              videoStreamClassNameOverride={`${screenWidth < 834 && "class-11"} ${
                screenWidth >= 834 && screenWidth < 1440 && "class-12"
              }`}
            />
          )}

          {screenWidth >= 834 && screenWidth < 1440 && (
            <>
              <Parameters className="parameters-instance" />
              <SimulationStreaming className="simulation-streaming-instance" />
              <Buttons className="buttons-instance" />
              <div className="nav-bar-2">
                <div className="group-42">
                  <div className="rectangle-8" />
                  <div className="rectangle-9" />
                  <div className="rectangle-10" />
                </div>
                <div className="control-chef-high-3">
                  <div className="div-4">
                    <div className="frame-8">
                      <div className="div-4">
                        <div className="div-wrapper-3">
                          <div className="overlap-9">
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
                          </div>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            </>
          )}

          {screenWidth >= 1440 && (
            <>
              <Blur className="blur-instance" />
              <Footer className="footer-instance" />
              <Graphs className="graphs-17" />
              <VideoStream
                className="video-stream-instance"
                videoStream="https://c.animaapp.com/zqIJEW6i/img/video-stream-3.svg"
              />
              <Parameters className="parameters-2" />
              <SimulationStreaming className="simulation-streaming-2" />
              <Buttons className="buttons-2" />
              <NavBar className="nav-bar-instance" />
            </>
          )}

          {screenWidth < 834 && (
            <>
              <Parameters
                className="parameters-3"
                divClassName="parameters-10"
                divClassNameOverride="parameters-13"
                groupClassName="parameters-6"
                groupClassName1="parameters-6"
                groupClassName10="parameters-28"
                groupClassName2="parameters-6"
                groupClassName3="parameters-17"
                groupClassName4="parameters-17"
                groupClassName5="parameters-21"
                groupClassName6="parameters-21"
                groupClassName7="parameters-17"
                groupClassName8="parameters-17"
                groupClassName9="parameters-28"
                groupClassNameOverride="parameters-6"
                overlapGroupClassName="parameters-7"
                overlapGroupClassNameOverride="parameters-7"
                overlapGroupWrapperClassName="parameters-11"
                overlapGroupWrapperClassNameOverride="parameters-11"
                pleaseEnterYourClassName="parameters-31"
                textClassName="parameters-4"
                textClassName1="parameters-14"
                textClassName10="parameters-30"
                textClassName2="parameters-15"
                textClassName3="parameters-16"
                textClassName4="parameters-19"
                textClassName5="parameters-20"
                textClassName6="parameters-23"
                textClassName7="parameters-24"
                textClassName8="parameters-25"
                textClassName9="parameters-26"
                textClassNameOverride="parameters-9"
                xPosKdClassName="parameters-5"
                xPosKdClassNameOverride="parameters-8"
                xPosKdWrapperClassName="parameters-7"
                xPosKiClassName="parameters-5"
                xPosKiClassNameOverride="parameters-12"
                xPosKiWrapperClassName="parameters-7"
                xPosKpClassName="parameters-5"
                xPosKpClassNameOverride="parameters-8"
                xSetPointClassName="parameters-27"
                xSetPointClassNameOverride="parameters-29"
                xSetPointWrapperClassName="parameters-7"
                xVelKdClassName="parameters-5"
                xVelKdClassNameOverride="parameters-18"
                xVelKdWrapperClassName="parameters-7"
                xVelKiClassName="parameters-5"
                xVelKiClassNameOverride="parameters-22"
                xVelKiWrapperClassName="parameters-7"
                xVelKpClassName="parameters-5"
                xVelKpClassNameOverride="parameters-18"
                xVelKpWrapperClassName="parameters-7"
                yPosKdClassName="parameters-5"
                yPosKdClassNameOverride="parameters-8"
                yPosKdWrapperClassName="parameters-7"
                yPosKiClassName="parameters-5"
                yPosKiClassNameOverride="parameters-12"
                yPosKiWrapperClassName="parameters-7"
                yPosKpClassName="parameters-5"
                yPosKpClassNameOverride="parameters-8"
                ySetPointClassName="parameters-27"
                ySetPointClassNameOverride="parameters-29"
                ySetPointWrapperClassName="parameters-7"
                yVelKdClassName="parameters-5"
                yVelKdClassNameOverride="parameters-18"
                yVelKdWrapperClassName="parameters-7"
                yVelKiClassName="parameters-5"
                yVelKiClassNameOverride="parameters-22"
                yVelKiWrapperClassName="parameters-7"
                yVelKpClassName="parameters-5"
                yVelKpClassNameOverride="parameters-18"
                yVelKpWrapperClassName="parameters-7"
              />
              <SimulationStreaming
                className="simulation-streaming-3"
                simulationStreamingClassName="simulation-streaming-4"
              />
              <Buttons
                className="buttons-3"
                groupClassName="buttons-4"
                groupClassNameOverride="buttons-7"
                overlapClassName="buttons-8"
                overlapClassNameOverride="buttons-5"
                overlapGroupClassName="buttons-5"
                overlapGroupClassNameOverride="buttons-8"
                overlapWrapperClassName="buttons-10"
                overlapWrapperClassNameOverride="buttons-12"
                resetClassName="buttons-9"
                setClassName="buttons-11"
                startClassName="buttons-9"
                stopClassName="buttons-6"
              />
              <div className="nav-bar-3">
                <div className="group-47">
                  <div className="rectangle-11" />
                  <div className="rectangle-12" />
                  <div className="rectangle-13" />
                </div>
                <div className="control-chef-high-4">
                  <div className="div-wrapper-4">
                    <div className="frame-11">
                      <div className="div-5">
                        <div className="div-wrapper-4">
                          <div className="overlap-10">
                            <div className="mask-group-8">
                              <div className="div-wrapper-4">
                                <div className="div-5">
                                  <div className="div-wrapper-4">
                                    <div className="div-5">
                                      <div className="div-wrapper-4">
                                        <div className="div-5">
                                          <div className="frame-12">
                                            <div className="overlap-group-8">
                                              <div className="group-48" />
                                              <div className="group-48" />
                                              <div className="mask-group-8">
                                                <div className="frame-13">
                                                  <div className="group-49" />
                                                  <div className="group-50" />
                                                  <div className="group-51" />
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
                            <img
                              className="mask-group-8"
                              alt="Mask group"
                              src="https://c.animaapp.com/zqIJEW6i/img/mask-group-10@2x.png"
                            />
                            <img
                              className="mask-group-8"
                              alt="Mask group"
                              src="https://c.animaapp.com/zqIJEW6i/img/mask-group-11@2x.png"
                            />
                            <img
                              className="mask-group-8"
                              alt="Mask group"
                              src="https://c.animaapp.com/zqIJEW6i/img/mask-group-12@2x.png"
                            />
                          </div>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
              <Graphs
                className="graphs-18"
                divClassName="graphs-24"
                divClassName1="graphs-35"
                divClassNameOverride="graphs-20"
                groupClassName="graphs-19"
                groupClassName1="graphs-26"
                groupClassName2="graphs-28"
                groupClassName3="graphs-30"
                groupClassName4="graphs-31"
                groupClassName5="graphs-33"
                groupClassNameOverride="graphs-22"
                rectangleClassName="graphs-20"
                rectangleClassName1="graphs-20"
                rectangleClassName2="graphs-20"
                rectangleClassName3="graphs-20"
                rectangleClassName4="graphs-20"
                rectangleClassName5="graphs-20"
                rectangleClassNameOverride="graphs-20"
                xPosClassName="graphs-21"
                xPosPidClassName="graphs-29"
                xVelClassName="graphs-25"
                xVelPidClassName="graphs-32"
                yPosClassName="graphs-23"
                yPosPidClassName="graphs-29"
                yVelClassName="graphs-27"
                yVelPidClassName="graphs-34"
              />
            </>
          )}
        </div>
      </div>
    </div>
  );
};
