//
// Created by jmkim on 12/17/17.
//

#ifndef FOLDIMATE_TRIGGER_HPP
#define FOLDIMATE_TRIGGER_HPP

namespace foldimate
{

  struct Trigger
  {
    virtual bool isOn () = 0;
    virtual bool isOff () = 0;
  };

}

#endif				//FOLDIMATE_TRIGGER_HPP
