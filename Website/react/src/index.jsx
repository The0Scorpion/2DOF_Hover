import "../global.css";
import "../styleguide.css";
import React, { Children } from "react";
import ReactDOMClient from "react-dom/client";
import { createBrowserRouter,RouterProvider } from "react-router-dom";
import { Hover } from "./screens/Hover";
import { Homepage } from "./screens/Homepage";
import { BallBalance } from "./screens/BallBalance";
import { Pendulum } from "./screens/Pendulum";
import { Servo } from "./screens/Servo"

const app = document.getElementById("app");
const root = ReactDOMClient.createRoot(app);
const router = createBrowserRouter([
    {
      path: "/",
      element: <Homepage/>,
    }, 
    {
        path: "/simulation-hover",
        element: <Hover/>,
    },
    {
        path: "/simulation-ballbalance",
        element: <BallBalance/>,
    },
    {
        path:"/simulation-servo",
        element:<Servo/>
    },
    {
        path:"/simulation-pendulum",
        element:<Pendulum/>
    },
]);

root.render(<React.StrictMode>
    <RouterProvider router={router} />
  </React.StrictMode>);