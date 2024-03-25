import React from "react";
import { useWindowWidth } from "../../breakpoints";
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
