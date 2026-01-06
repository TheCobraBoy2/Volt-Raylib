#include <raylib.h>
#include <VoltRayLib/Application.h>

#include "AppLayer.h"
#include "BackgroundLayer.h"

int main()
{
  VoltR::ApplicationSpecification appSpec;
  appSpec.Name = "Raylib App";
  appSpec.WindowSpec.Height = 500;
  appSpec.WindowSpec.Width = 500;

  VoltR::Application application(appSpec);
  application.PushLayer<BackgroundLayer>();
  application.PushLayer<AppLayer>();
  application.Run();
}