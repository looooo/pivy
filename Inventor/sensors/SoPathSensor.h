#ifndef COIN_SOPATHSENSOR_H
#define COIN_SOPATHSENSOR_H

/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2003 by Systems in Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using Coin with software that can not be combined with the GNU
 *  GPL, and for taking advantage of the additional benefits of our
 *  support services, please contact Systems in Motion about acquiring
 *  a Coin Professional Edition License.
 *
 *  See <URL:http://www.coin3d.org> for  more information.
 *
 *  Systems in Motion, Teknobyen, Abels Gate 5, 7030 Trondheim, NORWAY.
 *  <URL:http://www.sim.no>.
 *
\**************************************************************************/

#include <Inventor/sensors/SoDataSensor.h>

class SoPathSensorP;

#ifdef __PIVY__
%rename(SoPathSensor_scb_v) SoPathSensor::SoPathSensor(SoSensorCB * func, void * data);

%feature("shadow") SoPathSensor::SoPathSensor %{
def __init__(self,*args):
   if len(args) == 2:
      args = (args[0], (args[0], args[1]))
      self.this = apply(_pivy.new_SoPathSensor_scb_v,args)
      self.thisown = 1
      return
   self.this = apply(_pivy.new_SoPathSensor,args)
   self.thisown = 1
%}
#endif

class COIN_DLL_API SoPathSensor : public SoDataSensor {
  typedef SoDataSensor inherited;

public:
  SoPathSensor(void);
  SoPathSensor(SoSensorCB * func, void * data);
  virtual ~SoPathSensor(void);

  enum TriggerFilter {
    PATH =           0x1,
    NODES =          0x2,
    PATH_AND_NODES = 0x3
  };

  void setTriggerFilter(const TriggerFilter type);
  TriggerFilter getTriggerFilter(void) const;

  void attach(SoPath * path);
  void detach(void);
  SoPath * getAttachedPath(void) const;

protected:
  virtual void notify(SoNotList * l);

private:
  void commonConstructor(void);
  virtual void dyingReference(void);

  SoPathSensorP * pimpl;
};

#endif // !COIN_SOPATHSENSOR_H