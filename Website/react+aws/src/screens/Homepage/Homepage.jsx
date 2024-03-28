import React from "react";
import { useWindowWidth } from "../../breakpoints";
import { Footer } from "../../components/Footer";
import { NavBar } from "../../components/NavBar";
import { NavBar_2 } from "../../components/NavBar_2";
import { TestimonialsWrapper } from "../../components/TestimonialsWrapper";
import { Welcome } from "../../components/Welcome";
import { IntroWrapper } from "../../components/IntroWrapper";
import "./style.css";

export const Homepage = () => {
  const screenWidth = useWindowWidth();
  return (
    <div
      className="homepage"
      style={{
        background: "linear-gradient(135deg, rgb(5, 5, 24) 60%, rgb(26.25, 26.25, 126) 100%)",
        height:
          screenWidth < 834
            ? "2465px"
            : screenWidth >= 834 && screenWidth < 1349
              ? "1920px"
              : screenWidth >= 1360
                ? "2100px"
                : undefined,
        width:
          screenWidth < 834
            ? "360px"
            : screenWidth >= 834 && screenWidth < 1349
              ? "834px"
              : screenWidth >= 1349
                ? "1349px"
                : undefined,
      }}
    >
      {screenWidth < 834 && (
        <>
        </>
      )}

      {screenWidth >= 834 && screenWidth < 1349 && (
        <>
        </>
      )}

      {screenWidth >= 1349 && (
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
    </div>
  );
};
