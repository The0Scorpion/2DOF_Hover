import React from "react";
import { useWindowWidth } from "../../breakpoints";
import { Blur } from "../../components/Blur";
import { Buttons } from "../../components/Buttons";
import { Footer } from "../../components/Footer";
import { Graphs } from "../../components/Graphs";
import { NavBar } from "../../components/NavBar";
import { NavBar_2 } from "../../components/NavBar_2";
import { NavBar_3 } from "../../components/NavBar_3";
import { Parameters } from "../../components/Parameters";
import { SimulationStreaming } from "../../components/SimulationStreaming";
import { VideoStream } from "../../components/VideoStream";
import { Hover } from "../Hover";
import {Link} from "react-router-dom"
import "./style.css";

export const Servo = () => {
  const screenWidth = useWindowWidth();
  return (
    <>
    <div>Servo</div>
    <button><Link to="/">homepage</Link></button>
    </>
  );
};
