#include "AppLayer.h"
#include "BackgroundLayer.h"

#include "VoltRayLib/Application.h"
#include <raylib.h>

#include <print>

AppLayer::AppLayer()
{
}

AppLayer::~AppLayer()
{
}

void AppLayer::OnUpdate(float ts)
{
}

void AppLayer::OnRender()
{
  DrawText("Hello Its Working with layers", 100, 100, 20, BLACK);
}