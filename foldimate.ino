#include "servo/common/Folder.hpp"
#include "servo/doman/DomanServoController.hpp"
#include "sensor/common/Trigger.hpp"
#include "sensor/trigger/LightSensorTrigger.hpp"

void do_fold ();

foldimate::Folder * sv_left, *sv_right, *sv_body;
foldimate::Trigger * light_sensor;

void
setup ()
{
  sv_body = foldimate::DomanServoController::getInstance (9, 0, 130);
  sv_left = foldimate::DomanServoController::getInstance (10, 0, 130);
  sv_right = foldimate::DomanServoController::getInstance (11, 0, 130);
  light_sensor = foldimate::LightSensorTrigger::getInstance (A0, 800);
}

void
loop ()
{
  if (light_sensor->isOn ())
    {
      do_fold ();
    }
}

void
do_fold ()
{
  delay (5000);

  if (light_sensor->isOff ())
    {
      return;
    }
  sv_right->fold ();

  if (light_sensor->isOff ())
    {
      return;
    }
  sv_left->fold ();

  if (light_sensor->isOff ())
    {
      return;
    }
  sv_body->fold ();
}
