/*
We're constantly improving the code you see. 
Please share your feedback here: https://form.asana.com/?k=uvp-HPgd3_hyoXRBw1IcNg&d=1152665201300829
*/

/*import React from "react";
import "./style.css";

export const Graphs = ({
  className,
  groupClassName,
  rectangleClassName,
  xPosClassName,
  groupClassNameOverride,
  rectangleClassNameOverride,
  yPosClassName,
  divClassName,
  divClassNameOverride,
  xVelClassName,
  groupClassName1,
  rectangleClassName1,
  yVelClassName,
  groupClassName2,
  rectangleClassName2,
  xPosPidClassName,
  groupClassName3,
  rectangleClassName3,
  yPosPidClassName,
  groupClassName4,
  rectangleClassName4,
  xVelPidClassName,
  groupClassName5,
  rectangleClassName5,
  yVelPidClassName,
  divClassName1,
}) => {
  return (
    <div className={`graphs ${className}`}>
      <div className={`group-22 ${groupClassName}`}>
        <div className={`rectangle-5 ${rectangleClassName}`} />
        <div className={`text-wrapper-12 ${xPosClassName}`}>X&nbsp;&nbsp;Pos</div>
      </div>
      <div className={`group-23 ${groupClassNameOverride}`}>
        <div className={`rectangle-5 ${rectangleClassNameOverride}`} />
        <div className={`text-wrapper-12 ${yPosClassName}`}>Y Pos</div>
      </div>
      <div className={`group-24 ${divClassName}`}>
        <div className={`rectangle-6 ${divClassNameOverride}`} />
        <div className={`x-vel ${xVelClassName}`}> X Vel</div>
      </div>
      <div className={`group-25 ${groupClassName1}`}>
        <div className={`rectangle-5 ${rectangleClassName1}`} />
        <div className={`text-wrapper-12 ${yVelClassName}`}>Y Vel</div>
      </div>
      <div className={`group-26 ${groupClassName2}`}>
        <div className={`rectangle-6 ${rectangleClassName2}`} />
        <div className={`text-wrapper-13 ${xPosPidClassName}`}>X Pos Pid</div>
      </div>
      <div className={`group-27 ${groupClassName3}`}>
        <div className={`rectangle-6 ${rectangleClassName3}`} />
        <div className={`text-wrapper-13 ${yPosPidClassName}`}>Y Pos Pid</div>
      </div>
      <div className={`group-28 ${groupClassName4}`}>
        <div className={`rectangle-6 ${rectangleClassName4}`} />
        <div className={`x-vel-PID ${xVelPidClassName}`}>X Vel Pid</div>
      </div>
      <div className={`group-29 ${groupClassName5}`}>
        <div className={`rectangle-5 ${rectangleClassName5}`} />
        <div className={`text-wrapper-12 ${yVelPidClassName}`}>Y Vel Pid</div>
      </div>
      <div className={`text-wrapper-14 ${divClassName1}`}>Graphs</div>
    </div>
  );
};*/

import React, { useEffect, useRef } from "react";
import Chart from "chart.js/auto"; // Import Chart.js library
import "./style.css";

export const Graphs = ({
  className,
  groupClassName,
  rectangleClassName,
  xPosClassName,
  groupClassNameOverride,
  rectangleClassNameOverride,
  yPosClassName,
  divClassName,
  divClassNameOverride,
  xVelClassName,
  groupClassName1,
  rectangleClassName1,
  yVelClassName,
  groupClassName2,
  rectangleClassName2,
  xPosPidClassName,
  groupClassName3,
  rectangleClassName3,
  yPosPidClassName,
  groupClassName4,
  rectangleClassName4,
  xVelPidClassName,
  groupClassName5,
  rectangleClassName5,
  yVelPidClassName,
  divClassName1,
}) => {
  const chartRefs = {
    XPos: useRef(null),
    YPos: useRef(null),
    XVel: useRef(null),
    YVel: useRef(null),
    XPosPID: useRef(null),
    YPosPID: useRef(null),
    XVelPID: useRef(null),
    YVelPID: useRef(null),
  };

  useEffect(() => {
    const generateData = () => {
      const data = [];
      for (let x = -10; x <= 10; x += 0.1) {
        data.push({ x, y: mathFunction(x) });
      }
      return data;
    };

    const mathFunction = (x) => {
      return Math.pow(x, 2); // Example: sine function
    };

    const createGraph = (ctx, label) => {
      return new Chart(ctx, {
        type: "line",
        data: {
          datasets: [{
            label: label,
            borderColor: "black",
            borderWidth: 1,
            pointRadius: 0,
            data: generateData(),
            fill: false,
          }],
        },
        options: {
          scales: {
            x: {
              type: "linear",
              position: "bottom",
            },
            y: {
              type: "linear",
              position: "left",
            },
          },
        },
      });
    };

    // Create the graphs
    for (const [key, ref] of Object.entries(chartRefs)) {
      if (ref.current) {
        const chart = createGraph(ref.current.getContext("2d"), key);
        ref.current.chart = chart;
      }
    }

    // Cleanup function
    return () => {
      for (const ref of Object.values(chartRefs)) {
        if (ref.current && ref.current.chart) {
          ref.current.chart.destroy();
        }
      }
    };
  }, []);

  return (
    <div className={`graphs ${className}`}>
      <div className={`group-22 ${groupClassName}`}>
        <canvas ref={chartRefs.XPos} className={`rectangle-5 ${rectangleClassName}`}></canvas>
        <div className={`text-wrapper-12 ${xPosClassName}`}>X&nbsp;&nbsp;Pos</div>
      </div>
      <div className={`group-23 ${groupClassNameOverride}`}>
        <canvas ref={chartRefs.YPos} className={`rectangle-5 ${rectangleClassNameOverride}`}></canvas>
        <div className={`text-wrapper-12 ${yPosClassName}`}>Y Pos</div>
      </div>
      <div className={`group-24 ${divClassName}`}>
        <canvas ref={chartRefs.XVel} className={`rectangle-6 ${divClassNameOverride}`}></canvas>
        <div className={`x-vel ${xVelClassName}`}> X Vel</div>
      </div>
      <div className={`group-25 ${groupClassName1}`}>
        <canvas ref={chartRefs.YVel} className={`rectangle-5 ${rectangleClassName1}`}></canvas>
        <div className={`text-wrapper-12 ${yVelClassName}`}>Y Vel</div>
      </div>
      <div className={`group-26 ${groupClassName2}`}>
        <canvas ref={chartRefs.XPosPID} className={`rectangle-6 ${rectangleClassName2}`}></canvas>
        <div className={`text-wrapper-13 ${xPosPidClassName}`}>X Pos Pid</div>
      </div>
      <div className={`group-27 ${groupClassName3}`}>
        <canvas ref={chartRefs.YPosPID} className={`rectangle-6 ${rectangleClassName3}`}></canvas>
        <div className={`text-wrapper-13 ${yPosPidClassName}`}>Y Pos Pid</div>
      </div>
      <div className={`group-28 ${groupClassName4}`}>
        <canvas ref={chartRefs.XVelPID} className={`rectangle-6 ${rectangleClassName4}`}></canvas>
        <div className={`x-vel-PID ${xVelPidClassName}`}>X Vel Pid</div>
      </div>
      <div className={`group-29 ${groupClassName5}`}>
        <canvas ref={chartRefs.YVelPID} className={`rectangle-5 ${rectangleClassName5}`}></canvas>
        <div className={`text-wrapper-12 ${yVelPidClassName}`}>Y Vel Pid</div>
      </div>
      <div className={`text-wrapper-14 ${divClassName1}`}>Graphs</div>
    </div>
  );
};



