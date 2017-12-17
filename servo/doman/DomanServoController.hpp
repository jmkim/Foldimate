//
// Created by jmkim on 12/17/17.
//

#ifndef FOLDIMATE_DOMANSERVOCONTROLLER_HPP
#define FOLDIMATE_DOMANSERVOCONTROLLER_HPP

#include <Servo.h>
#include "../common/ServoController.hpp"
#include "../common/Folder.hpp"

namespace foldimate
{

  class DomanServoController:public ServoController, public Folder
  {
  public:
    static
      DomanServoController *getInstance (const uint8_t & pin,
					 const int &angle_min,
					 const int &angle_max,
					 const long &delay_ms = 1500)
    {
      return new DomanServoController (pin, angle_min, angle_max, delay_ms);
    }

    void setAngle (int angle)
    {
      servo.write (angle);
      delay (15);
    }

    void fold ()
    {
      setAngle (angle_max_);
      delay (delay_ms_);
      setAngle (angle_min_);
      delay (delay_ms_);
    }

  protected:
    DomanServoController (const uint8_t & pin, const int &angle_min,
			  const int &angle_max,
			  const long &delay_ms):angle_min_ (angle_min),
      angle_max_ (angle_max), delay_ms_ (delay_ms)
    {
      servo.attach (pin);
      servo.write (angle_min_);
    }

  private:
    Servo servo;
    const int angle_min_;
    const int angle_max_;
    const long delay_ms_;
  };

}

#endif //FOLDIMATE_DOMANSERVOCONTROLLER_HPP
