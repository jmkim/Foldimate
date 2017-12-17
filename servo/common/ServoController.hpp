//
// Created by jmkim on 12/8/17.
//

#ifndef FOLDIMATE_SERVOCONTROLLER_HPP
#define FOLDIMATE_SERVOCONTROLLER_HPP

namespace foldimate
{

  struct ServoController
  {
    virtual void setAngle (int) = 0;
  };

}

#endif				//FOLDIMATE_SERVOCONTROLLER_HPP
