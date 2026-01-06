#pragma once

#include "VoltRayLib/Layer.h"

class AppLayer : public VoltR::Layer
{
public:
  AppLayer();
  virtual ~AppLayer();

  virtual void OnUpdate(float ts) override;
  virtual void OnRender() override;

private:
};