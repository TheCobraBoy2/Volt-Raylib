#include <raylib.h>
#include <VoltRayLib/Application.h>
#include "AppLayer.h"

int main()
{
  // const int screenWidth = 800;
  // const int screenHeight = 600;
  // InitWindow(screenWidth, screenHeight, "raylib window");
  // SetTargetFPS(60);
  // while (!WindowShouldClose())
  // {
  //   BeginDrawing();
  //   ClearBackground(RAYWHITE);
  //   DrawText("It works!", 20, 20, 20, BLACK);
  //   EndDrawing();
  // }
  // CloseWindow();
  // return 0;

  VoltR::ApplicationSpecification appSpec;
  appSpec.Name = "Raylib App";
  appSpec.WindowSpec.Height = 500;
  appSpec.WindowSpec.Width = 500;

  VoltR::Application application(appSpec);
  application.PushLayer<AppLayer>();
  application.Run();
}