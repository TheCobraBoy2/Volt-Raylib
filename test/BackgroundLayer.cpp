#include "BackgroundLayer.h"
#include "AppLayer.h"

#include "VoltRayLib/Application.h"
#include <raylib.h>

#include <print>

BackgroundLayer::BackgroundLayer()
{
}

BackgroundLayer::~BackgroundLayer()
{
}

void BackgroundLayer::OnUpdate(float ts)
{
}

void BackgroundLayer::OnRender()
{
  ClearBackground(RAYWHITE);
}