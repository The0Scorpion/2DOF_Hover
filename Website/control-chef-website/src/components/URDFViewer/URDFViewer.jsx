import React, { useEffect, useRef, useState } from 'react';
import * as THREE from 'three';
import URDFLoader from 'urdf-loader';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js';

export const URDFViewer = ({ 
  urdfUrl,
  width,
  height,
  className,
  joint1,
  joint2,
}) => {
  const containerRef = useRef();
  const sceneRef = useRef();
  const cameraRef = useRef(); 
  const rendererRef = useRef();
  const robotRef = useRef();
  
  const setonce = useRef(false);
  const controlsRef = useRef();

  useEffect(() => {
    if (setonce.current) return;

    const container = containerRef.current;
    const scene = new THREE.Scene();
    scene.background = new THREE.Color(0x141450); // Background color as hex

    const camera = new THREE.PerspectiveCamera(75, width / height, 0.001, 1000); // Use width and height props for aspect ratio
    camera.position.set(5, 5, 5); // Set initial camera position
    const renderer = new THREE.WebGLRenderer({ antialias: true });

    const ambientLight = new THREE.AmbientLight(0xffffff, 0.5); // Pure white ambient light with full intensity
    const directionalLight = new THREE.DirectionalLight(0xffffff, 0.5); // Pure white directional light with full intensity

    // Add the lights to the scene
    scene.add(ambientLight);
    scene.add(directionalLight);

    renderer.setSize(width, height); // Use width and height props for renderer size
    container.appendChild(renderer.domElement);

    setonce.current = true;

    const loader = new URDFLoader();
    loader.load(urdfUrl,
      (robot) => {
        robotRef.current = robot;
        robot.position.set(0, 0, 0);
        robot.rotation.set(0, 0, 0);
        
        scene.add(robot);

        setTimeout(() => {
          const box = new THREE.Box3().setFromObject(robot);
          const center = box.getCenter(new THREE.Vector3());
          const size = box.getSize(new THREE.Vector3());
          const maxDim = Math.max(size.x, size.y, size.z);
          const fov = camera.fov * (Math.PI / 180);
          const cameraZ = Math.abs((maxDim / 2) / Math.tan(fov / 2));
          /*const controls = new OrbitControls(camera, renderer.domElement);
          controls.addEventListener('change', () => {
            const currentPosition = camera.position.clone();
            const currentRotation = camera.rotation.clone();
            console.log('Current Camera Position:', currentPosition);
            console.log('Current Camera Rotation:', currentRotation);
          });
          controlsRef.current = controls;*/
          camera.position.set(0.12, -0.8, 0.5); // Set the target of the controls to the origin
          camera.rotation.set(1, 0, 0);//(2, 1.8, -0.35);
          const currentPosition = camera.position.clone();
            const currentRotation = camera.rotation.clone();
            console.log('Current Camera Position:', currentPosition);
            console.log('Current Camera Rotation:', currentRotation);
          cameraRef.current=camera;
         
            
          

          // Debugging: Log the available joints
          //console.log('Available Joints:', robot.joints);
        }, 300);
      },
      undefined,
      (error) => {
        console.error("Error loading URDF file:", error);
      });

    const animate = () => {
      requestAnimationFrame(animate);
      
      renderer.render(scene, camera);
    };
    animate();

    const handleResize = () => {
      camera.aspect = width / height;
      camera.updateProjectionMatrix();
      renderer.setSize(width, height);
    };

    window.addEventListener('resize', handleResize);

    return () => {
      window.removeEventListener('resize', handleResize);
    };
  }, [urdfUrl, width, height]);

  useEffect(() => {
    if (robotRef.current) {
      console.warn('calling use effect');
      if (robotRef.current.joints['joint1']) {
        robotRef.current.joints['joint1'].setJointValue(joint1);
        console.log(`Updated joint1 to ${joint1}`);
      } else {
        console.warn('Joint "joint1" not found');
      }
      if (robotRef.current.joints['joint2']) {
        robotRef.current.joints['joint2'].setJointValue(joint2);
        console.log(`Updated joint2 to ${joint2}`);
      } else {
        console.warn('Joint "joint2" not found');
      }
    }
  }, [joint1, joint2]);

  const handleJoint1Change = (e) => {
    const value = parseFloat(e.target.value);
    console.log('Joint 1 Slider Value:', value);
    setJoint1(value);
  };

  const handleJoint2Change = (e) => {
    const value = parseFloat(e.target.value);
    console.log('Joint 2 Slider Value:', value);
    setJoint2(value);
  };

  const moveCameraToPosition1 = () => {
  const camera = cameraRef.current;
  if (camera) {
    camera.position.set(0.12, -0.8, 0.5); // Set the target of the controls to the origin
    camera.rotation.set(1, 0, 0); // Rotate the camera to the desired orientation
  }
};

const moveCameraToPosition2 = () => {
  const camera = cameraRef.current;
  if (camera) {
    camera.position.set(0.9, -0.3, 0.5);
    camera.rotation.set(0.55+1.57,1.8,-0.7);//(2, 1.8, -0.35);
          
  }
};

const moveCameraToPosition3 = () => {
  const camera = cameraRef.current;
  if (camera) {
    camera.position.set(0.7, -0.3, 0.20);
          //camera.lookAt(0,-0.1,.25);
    camera.rotation.set( 1.48+1.57,0.86,-1.46); // Set the camera rotation (in radians)
  }
};

  return (
    <div className={`urdf ${className}`} ref={containerRef}>
      <div style={{ position: 'absolute', top: '10px', left: '10px', zIndex: 1 }}>
        <button onClick={moveCameraToPosition1}>Camera Position 1</button>
        <button onClick={moveCameraToPosition2}>Camera Position 2</button>
        <button onClick={moveCameraToPosition3}>Camera Position 3</button>
      </div>
    </div>
  );
};
