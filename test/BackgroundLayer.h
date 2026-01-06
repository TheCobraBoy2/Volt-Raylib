#pragma once

#include "VoltRayLib/Layer.h"

class BackgroundLayer : public VoltR::Layer
{
public:
  BackgroundLayer();
  virtual ~BackgroundLayer();

  virtual void OnUpdate(float ts) override;
  virtual void OnRender() override;

private:
};