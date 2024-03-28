import "../global.css";
import "../styleguide.css";
import React, { Children } from "react";
/*import { Amplify } from 'aws-amplify';*/
import ReactDOMClient from "react-dom/client";
import { createBrowserRouter,RouterProvider } from "react-router-dom";
import { Homepage } from "./screens/Homepage/Homepage";

const app = document.getElementById("app");
const root = ReactDOMClient.createRoot(app);
root.render(<Homepage/>);
/*const router = createBrowserRouter([
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
    {
        path:"/log-in",
        element:<LoginAnd/>
    },
    {
        path:"/registration",
        element:<Registration/>
    },
]);

root.render(<React.StrictMode>
    <RouterProvider router={router} />
  </React.StrictMode>);*/