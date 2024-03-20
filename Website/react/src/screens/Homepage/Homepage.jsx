import React from "react";
import { useWindowWidth } from "../../breakpoints";
import { Blur } from "../../components/Blur";
import { Footer } from "../../components/Footer";
import { NavBar } from "../../components/NavBar";
import { NavBar_2 } from "../../components/NavBar_2";
import { NavBar_3 } from "../../components/NavBar_3";
import { Testimonials } from "../../components/Testimonials";
import { TestimonialsWrapper } from "../../components/TestimonialsWrapper";
import { Welcome } from "../../components/Welcome";
import { Intro } from "../../components/Intro";
import { IntroWrapper } from "../../components/IntroWrapper";
import { ButtonIntro } from "../../components/ButtonIntro";
import {Link} from "react-router-dom";
import "./style.css";

export const Homepage = () => {
  const screenWidth = useWindowWidth();
  return (
    <div
      className="welcome-and"
      style={{
        backgroundColor:
          (screenWidth >= 834 && screenWidth < 1440) || screenWidth < 834
            ? "#050814"
            : screenWidth >= 1440
            ? "#050814"
            : undefined,
      }}
    >
      <div
        className="overlap-wrapper-2"
        style={{
          backgroundColor:
            (screenWidth >= 834 && screenWidth < 1440) || screenWidth < 834
              ? "#050814"
              : screenWidth >= 1440
              ? "#050814"
              : undefined,
          height:
            screenWidth < 834
              ? "2924px"
              : screenWidth >= 834 && screenWidth < 1440
              ? "2069px"
              : screenWidth >= 1440
              ? "2540px"
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
          className="overlap-7"
          style={{
            height:
              screenWidth < 834
                ? "3083px"
                : screenWidth >= 834 && screenWidth < 1440
                ? "2647px"
                : screenWidth >= 1440
                ? "3025px"
                : undefined,
            left:
              screenWidth < 834
                ? "-256px"
                : screenWidth >= 834 && screenWidth < 1440
                ? "-181px"
                : screenWidth >= 1440
                ? "-763px"
                : undefined,
            top:
              screenWidth < 834
                ? "-159px"
                : screenWidth >= 834 && screenWidth < 1440
                ? "-515px"
                : screenWidth >= 1440
                ? "-485px"
                : undefined,
            width:
              screenWidth < 834
                ? "724px"
                : screenWidth >= 834 && screenWidth < 1440
                ? "1098px"
                : screenWidth >= 1440
                ? "2587px"
                : undefined,
          }}
        >
          <Blur
            className={`${screenWidth >= 834 && screenWidth < 1440 && "class-4"} ${screenWidth >= 1440 && "class-5"} ${
              screenWidth < 834 && "class-6"
            }`}
            divClassName={`${screenWidth >= 834 && screenWidth < 1440 && "class-10"} ${
              screenWidth >= 1440 && "class-11"
            } ${screenWidth < 834 && "class-12"}`}
            ellipseClassName={`${screenWidth >= 834 && screenWidth < 1440 && "class"} ${
              screenWidth >= 1440 && "class-2"
            } ${screenWidth < 834 && "class-3"}`}
            ellipseClassNameOverride={`${screenWidth >= 834 && screenWidth < 1440 && "class-7"} ${
              screenWidth >= 1440 && "class-8"
            } ${screenWidth < 834 && "class-9"}`}
          />
          {((screenWidth >= 834 && screenWidth < 1440) || screenWidth < 834) && (
            <footer
              className="footer-2"
              style={{
                height: screenWidth < 834 ? "77px" : screenWidth >= 834 && screenWidth < 1440 ? "141px" : undefined,
                left: screenWidth < 834 ? "202px" : screenWidth >= 834 && screenWidth < 1440 ? "181px" : undefined,
                top: screenWidth < 834 ? "3006px" : screenWidth >= 834 && screenWidth < 1440 ? "2443px" : undefined,
                width: screenWidth < 834 ? "468px" : screenWidth >= 834 && screenWidth < 1440 ? "834px" : undefined,
              }}
            >
              <div
                className="group-16"
                style={{
                  height: screenWidth < 834 ? "64px" : screenWidth >= 834 && screenWidth < 1440 ? "117px" : undefined,
                  left: screenWidth < 834 ? "61px" : screenWidth >= 834 && screenWidth < 1440 ? "108px" : undefined,
                  width: screenWidth < 834 ? "346px" : screenWidth >= 834 && screenWidth < 1440 ? "617px" : undefined,
                }}
              >
                <div
                  className="group-17"
                  style={{
                    height: screenWidth < 834 ? "53px" : screenWidth >= 834 && screenWidth < 1440 ? "96px" : undefined,
                    left: screenWidth < 834 ? "10px" : screenWidth >= 834 && screenWidth < 1440 ? "19px" : undefined,
                    top: screenWidth < 834 ? "4px" : screenWidth >= 834 && screenWidth < 1440 ? "9px" : undefined,
                    width: screenWidth < 834 ? "326px" : screenWidth >= 834 && screenWidth < 1440 ? "582px" : undefined,
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
                      className="group-28"
                      style={{
                        height:
                          screenWidth < 834 ? "17px" : screenWidth >= 834 && screenWidth < 1440 ? "32px" : undefined,
                      }}
                    >
                      <div
                        className="frame-5"
                        style={{
                          height:
                            screenWidth < 834 ? "17px" : screenWidth >= 834 && screenWidth < 1440 ? "32px" : undefined,
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
                            className="frame-8"
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
                              className="overlap-8"
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
                                  className="frame-8"
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
                                    className="group-28"
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
                                            className="group-28"
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
                                                className="overlap-group-6"
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
                                                  className="group-18"
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
                                                  className="group-19"
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
                                                  className="text"
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
                                                      className="group-20"
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
                                                      className="group-21"
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
                                                      className="group-22"
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
                                    ? "https://c.animaapp.com/8gKnAxyl/img/mask-group-16@2x.png"
                                    : screenWidth >= 834 && screenWidth < 1440
                                    ? "https://c.animaapp.com/8gKnAxyl/img/mask-group-22@2x.png"
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
                                    ? "https://c.animaapp.com/8gKnAxyl/img/mask-group-17@2x.png"
                                    : screenWidth >= 834 && screenWidth < 1440
                                    ? "https://c.animaapp.com/8gKnAxyl/img/mask-group-23@2x.png"
                                    : undefined
                                }
                              />
                              <img
                                className="mask-group-7"
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
                                    ? "https://c.animaapp.com/8gKnAxyl/img/mask-group-18@2x.png"
                                    : screenWidth >= 834 && screenWidth < 1440
                                    ? "https://c.animaapp.com/8gKnAxyl/img/mask-group-24@2x.png"
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
                    className="group-23"
                    style={{
                      height:
                        screenWidth < 834 ? "53px" : screenWidth >= 834 && screenWidth < 1440 ? "96px" : undefined,
                      left:
                        screenWidth < 834 ? "287px" : screenWidth >= 834 && screenWidth < 1440 ? "512px" : undefined,
                      width: screenWidth < 834 ? "41px" : screenWidth >= 834 && screenWidth < 1440 ? "72px" : undefined,
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
                      className="group-24"
                      style={{
                        height:
                          screenWidth < 834 ? "39px" : screenWidth >= 834 && screenWidth < 1440 ? "70px" : undefined,
                        left: screenWidth < 834 ? "5px" : screenWidth >= 834 && screenWidth < 1440 ? "7px" : undefined,
                        top: screenWidth < 834 ? "14px" : screenWidth >= 834 && screenWidth < 1440 ? "26px" : undefined,
                        width:
                          screenWidth < 834 ? "42px" : screenWidth >= 834 && screenWidth < 1440 ? "71px" : undefined,
                      }}
                    >
                      <div
                        className="overlap-group-7"
                        style={{
                          height:
                            screenWidth < 834 ? "39px" : screenWidth >= 834 && screenWidth < 1440 ? "70px" : undefined,
                          width:
                            screenWidth < 834 ? "34px" : screenWidth >= 834 && screenWidth < 1440 ? "63px" : undefined,
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
                              screenWidth < 834 ? "3px" : screenWidth >= 834 && screenWidth < 1440 ? "5px" : undefined,
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
                    className="group-25"
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
                      className="group-26"
                      style={{
                        height:
                          screenWidth < 834 ? "20px" : screenWidth >= 834 && screenWidth < 1440 ? "35px" : undefined,
                        left:
                          screenWidth < 834 ? "15px" : screenWidth >= 834 && screenWidth < 1440 ? "26px" : undefined,
                        top: screenWidth < 834 ? "14px" : screenWidth >= 834 && screenWidth < 1440 ? "26px" : undefined,
                        width:
                          screenWidth < 834 ? "37px" : screenWidth >= 834 && screenWidth < 1440 ? "65px" : undefined,
                      }}
                    >
                      <div
                        className="overlap-group-8"
                        style={{
                          height:
                            screenWidth < 834 ? "20px" : screenWidth >= 834 && screenWidth < 1440 ? "35px" : undefined,
                          width:
                            screenWidth < 834 ? "33px" : screenWidth >= 834 && screenWidth < 1440 ? "61px" : undefined,
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
                              screenWidth < 834 ? "3px" : screenWidth >= 834 && screenWidth < 1440 ? "5px" : undefined,
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
                className="group-27"
                style={{
                  height: screenWidth < 834 ? "7px" : screenWidth >= 834 && screenWidth < 1440 ? "12px" : undefined,
                  top: screenWidth < 834 ? "71px" : screenWidth >= 834 && screenWidth < 1440 ? "129px" : undefined,
                  width: screenWidth < 834 ? "470px" : screenWidth >= 834 && screenWidth < 1440 ? "836px" : undefined,
                }}
              >
                <div
                  className="overlap-9"
                  style={{
                    height: screenWidth < 834 ? "7px" : screenWidth >= 834 && screenWidth < 1440 ? "12px" : undefined,
                    width: screenWidth < 834 ? "468px" : screenWidth >= 834 && screenWidth < 1440 ? "834px" : undefined,
                  }}
                >
                  <div
                    className="rectangle-4"
                    style={{
                      height: screenWidth < 834 ? "6px" : screenWidth >= 834 && screenWidth < 1440 ? "10px" : undefined,
                      width:
                        screenWidth < 834 ? "468px" : screenWidth >= 834 && screenWidth < 1440 ? "834px" : undefined,
                    }}
                  />
                  <p
                    className="copyright-2"
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
                      height: screenWidth < 834 ? "7px" : screenWidth >= 834 && screenWidth < 1440 ? "12px" : undefined,
                      left: screenWidth < 834 ? "46px" : screenWidth >= 834 && screenWidth < 1440 ? "229px" : undefined,
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
          )}

          {screenWidth < 834 && <Testimonials className="testimonials-instance" />}

          {screenWidth >= 834 && screenWidth < 1440 && (
            <>
              <NavBar_2 className="nav-bar-tab" />
              <IntroWrapper
                className="intro-instance"
                divClassName="instance-node"
                homeBanner="https://c.animaapp.com/8gKnAxyl/img/home-banner-1-1-3@2x.png"
                homeBannerClassName="intro-2"
              />
              <ButtonIntro
                className="button-intro-instance"
                divClassName="button-intro-7"
                divClassNameOverride="button-intro-9"
                experimentsClassName="button-intro-5"
                overlapClassName="button-intro-6"
                overlapClassNameOverride="button-intro-6"
                overlapGroupClassName="button-intro-3"
                reservationClassName="button-intro-8"
                theoriesExplanationClassName="button-intro-2"
                theoriesExplanationClassNameOverride="button-intro-4"
              />
            </>
          )}

          {((screenWidth >= 834 && screenWidth < 1440) || screenWidth < 834) && (
            <Welcome
              abstractClassName={`${screenWidth < 834 && "class-21"} ${
                screenWidth >= 834 && screenWidth < 1440 && "class-22"
              }`}
              className={`${screenWidth < 834 && "class-19"} ${screenWidth >= 834 && screenWidth < 1440 && "class-20"}`}
              creatingAnIotLabClassName={`${screenWidth < 834 && "class-15"} ${
                screenWidth >= 834 && screenWidth < 1440 && "class-16"
              }`}
              ourVisionClassName={`${screenWidth < 834 && "class-23"} ${
                screenWidth >= 834 && screenWidth < 1440 && "class-24"
              }`}
              text={
                screenWidth < 834
                  ? <> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Abstract</> 
                  : screenWidth >= 834 && screenWidth < 1440
                  ? "Abstract"
                  : undefined
              }
              text1={
                screenWidth < 834
                  ? <> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Our Vision</> 
                  : screenWidth >= 834 && screenWidth < 1440
                  ? "Our Vision"
                  : undefined
              }
              text2={
                screenWidth < 834 ? (
                  <>
                    Welcome To <br />
                    control Chef
                  </>
                ) : screenWidth >= 834 && screenWidth < 1440 ? (
                  "Welcome To Control Chef"
                ) : undefined
              }
              theAvailabilityOfClassName={`${screenWidth < 834 && "class-17"} ${
                screenWidth >= 834 && screenWidth < 1440 && "class-18"
              }`}
              welcomeToControlClassName={`${screenWidth < 834 && "class-13"} ${
                screenWidth >= 834 && screenWidth < 1440 && "class-14"
              }`}
            />
          )}

          {screenWidth >= 834 && screenWidth < 1440 && (
            <TestimonialsWrapper
              className="testimonials-3"
              divClassName="testimonials-9"
              divClassName1="testimonials-9"
              divClassName2="testimonials-10"
              divClassName3="testimonials-9"
              divClassName4="testimonials-10"
              divClassNameOverride="testimonials-10"
              ellipseClassName="testimonials-8"
              ellipseClassName1="testimonials-8"
              ellipseClassNameOverride="testimonials-8"
              img="https://c.animaapp.com/8gKnAxyl/img/mask-group-26@2x.png"
              imgClassName="testimonials-7"
              maskGroup="https://c.animaapp.com/8gKnAxyl/img/mask-group-25@2x.png"
              maskGroup1="https://c.animaapp.com/8gKnAxyl/img/mask-group-27@2x.png"
              maskGroupClassName="testimonials-7"
              maskGroupClassNameOverride="testimonials-7"
              overlapClassName="testimonials-5"
              overlapClassNameOverride="testimonials-5"
              overlapGroupClassName="testimonials-5"
              overlapGroupClassNameOverride="testimonials-13"
              overlapWrapperClassName="testimonials-12"
              readWhatOthersClassName="testimonials-14"
              rectangleClassName="testimonials-6"
              rectangleClassName1="testimonials-6"
              rectangleClassNameOverride="testimonials-6"
              testimonialItemClassName="testimonials-4"
              testimonialItemClassNameOverride="testimonials-11"
              testimonialsClassName="testimonials-15"
            />
          )}

          {screenWidth >= 1440 && (
            <>
              <Footer className="footer-instance" />
              <TestimonialsWrapper
                className="testimonials-16"
                img="https://c.animaapp.com/8gKnAxyl/img/mask-group-33@2x.png"
                maskGroup="https://c.animaapp.com/8gKnAxyl/img/mask-group-33@2x.png"
                maskGroup1="https://c.animaapp.com/8gKnAxyl/img/mask-group-33@2x.png"
              />
              <Welcome
                className="welcome-instance"
                text="Abstract"
                text1="Our Vision"
                text2="Welcome To Control Chef"
              />
              <ButtonIntro className="button-intro-10" />
              <IntroWrapper
                className="intro-3"
                homeBanner="https://c.animaapp.com/8gKnAxyl/img/home-banner-1-1-4@2x.png"
              />
              <NavBar
                className="nav-bar-instance"
                maskGroup="https://c.animaapp.com/8gKnAxyl/img/mask-group-35@2x.png"
              />
            </>
          )}

          {screenWidth < 834 && (
            <>
              <Intro className="intro-4" />
              <NavBar_3 className="nav-bar-tab-instance" />
            </>
          )}
        </div>
      </div>
    </div>
  );
};
