/*
We're constantly improving the code you see. 
Please share your feedback here: https://form.asana.com/?k=uvp-HPgd3_hyoXRBw1IcNg&d=1152665201300829
*/

import PropTypes from "prop-types";
import React from "react";
import "./style.css";

export const TestimonialsWrapper = ({
  className,
  testimonialItemClassName,
  overlapGroupClassName,
  rectangleClassName,
  maskGroupClassName,
  maskGroup = "https://c.animaapp.com/8gKnAxyl/img/mask-group-33@2x.png",
  ellipseClassName,
  divClassName,
  divClassNameOverride,
  testimonialItemClassNameOverride,
  overlapClassName,
  rectangleClassNameOverride,
  maskGroupClassNameOverride,
  img = "https://c.animaapp.com/8gKnAxyl/img/mask-group-33@2x.png",
  ellipseClassNameOverride,
  divClassName1,
  divClassName2,
  overlapWrapperClassName,
  overlapClassNameOverride,
  rectangleClassName1,
  imgClassName,
  maskGroup1 = "https://c.animaapp.com/8gKnAxyl/img/mask-group-33@2x.png",
  ellipseClassName1,
  divClassName3,
  divClassName4,
  overlapGroupClassNameOverride,
  readWhatOthersClassName,
  testimonialsClassName,
}) => {
  return (
    <div className={`testimonials-wrapper ${className}`}>
      <div className={`testimonial-item-4 ${testimonialItemClassName}`}>
        <div className={`overlap-group-4 ${overlapGroupClassName}`}>
          <div className={`rectangle-3 ${rectangleClassName}`} />
          <img className={`mask-group-2 ${maskGroupClassName}`} alt="Mask group" src={maskGroup} />
          <div className={`ellipse-4 ${ellipseClassName}`} />
          <div className={`text-wrapper-10 ${divClassName}`}>Abdelrahman Magdy</div>
          <div className={`text-wrapper-11 ${divClassNameOverride}`}>
            bbddbsbowbruberubvierbfeurbfuebvebrvuaerbvueanjrvnleanvelvnaejbveayvrvaek.jbvcebvwbvbuwrwbvjkbaysrevve
          </div>
        </div>
      </div>
      <div className={`testimonial-item-5 ${testimonialItemClassNameOverride}`}>
        <div className={`overlap-group-4 ${overlapClassName}`}>
          <div className={`rectangle-3 ${rectangleClassNameOverride}`} />
          <img className={`mask-group-2 ${maskGroupClassNameOverride}`} alt="Mask group" src={img} />
          <div className={`ellipse-4 ${ellipseClassNameOverride}`} />
          <div className={`text-wrapper-10 ${divClassName1}`}>Abdelrahman Magdy</div>
          <div className={`text-wrapper-11 ${divClassName2}`}>
            bbddbsbowbruberubvierbfeurbfuebvebrvuaerbvueanjrvnleanvelvnaejbveayvrvaek.jbvcebvwbvbuwrwbvjkbaysrevve
          </div>
        </div>
      </div>
      <div className={`testimonial-item-6 ${overlapWrapperClassName}`}>
        <div className={`overlap-group-4 ${overlapClassNameOverride}`}>
          <div className={`rectangle-3 ${rectangleClassName1}`} />
          <img className={`mask-group-2 ${imgClassName}`} alt="Mask group" src={maskGroup1} />
          <div className={`ellipse-4 ${ellipseClassName1}`} />
          <div className={`text-wrapper-10 ${divClassName3}`}>Abdelrahman Magdy</div>
          <div className={`text-wrapper-11 ${divClassName4}`}>
            bbddbsbowbruberubvierbfeurbfuebvebrvuaerbvueanjrvnleanvelvnaejbveayvrvaek.jbvcebvwbvbuwrwbvjkbaysrevve
          </div>
        </div>
      </div>
      <div className={`overlap-5 ${overlapGroupClassNameOverride}`}>
        <p className={`read-what-others-2 ${readWhatOthersClassName}`}>Read What Others Have To Say</p>
        <div className={`testimonials-2 ${testimonialsClassName}`}>Testimonials</div>
      </div>
    </div>
  );
};

TestimonialsWrapper.propTypes = {
  maskGroup: PropTypes.string,
  img: PropTypes.string,
  maskGroup1: PropTypes.string,
};
