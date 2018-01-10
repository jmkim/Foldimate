//
// Created by jmkim on 12/17/17.
//

#ifndef FOLDIMATE_LIGHTSENSORTRIGGER_HPP
#define FOLDIMATE_LIGHTSENSORTRIGGER_HPP

#include <Servo.h>
#include "../common/Trigger.hpp"

namespace foldimate
{

  class LightSensorTrigger:public Trigger
  {
  public:
    static
      LightSensorTrigger *getInstance (const uint8_t & pin,
				       const int &threshold = 300)
    {
      return new LightSensorTrigger (pin, threshold);
    }

    bool isOn ()
    {
      return (analogRead (pin_) < threshold_);
    }

    bool isOff ()
    {
      return !isOn ();
    };

    int getValue ()
    {
      return analogRead (pin_);
    }

  protected:
  LightSensorTrigger (const uint8_t & pin, const int &threshold):pin_ (pin),
      threshold_
      (threshold)
    {
    }

  private:
    const uint8_t pin_;
    const int threshold_;
  };

}

#endif //FOLDIMATE_LIGHTSENSORTRIGGER_HPP
