// #include <raylib.h>

// int main()
// {
//   const int screenWidth = 800;
//   const int screenHeight = 600;
//   InitWindow(screenWidth, screenHeight, "basic window");
//   SetTargetFPS(60);
//   while (!WindowShouldClose())
//   {
//     BeginDrawing();
//     ClearBackground(RAYWHITE);
//     DrawText("It works!", 20, 20, 20, BLACK);
//     EndDrawing();
//   }
//   CloseWindow();
//   return 0;
// }

#include <VoltRaylib/Application.h>
#include <raylib.h>

#include <print>

namespace VoltR
{
  static Application *s_Application = nullptr;

  Application::Application(const ApplicationSpecification &specification) : m_Specification(specification)
  {
    s_Application = this;

    if (m_Specification.WindowSpec.Title.empty())
      m_Specification.WindowSpec.Title = m_Specification.Name;

    m_Window = std::make_shared<Window>(m_Specification.WindowSpec);
    m_Window->Create();
  }

  Application::~Application()
  {
    m_Window->Destroy();
    s_Application = nullptr;
  }

  void Application::Run()
  {
    m_Running = true;

    while (m_Running)
    {
      if (m_Window->ShouldClose())
      {
        Stop();
        break;
      }

      float deltaTime = GetFrameTime();

      for (const std::unique_ptr<Layer> &layer : m_LayerStack)
        layer->OnUpdate(deltaTime);

      BeginDrawing();
      for (const std::unique_ptr<Layer> &layer : m_LayerStack)
        layer->OnRender();
      EndDrawing();
    }
  }

  void Application::Stop()
  {
    m_Running = false;
  }
}