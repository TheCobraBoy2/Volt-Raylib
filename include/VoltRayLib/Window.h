#pragma once

#include <string>

namespace VoltR
{
  struct WindowSpecification
  {
    std::string Title;
    int Width = 1280;
    int Height = 720;
  };

  class Window
  {
  public:
    Window(const WindowSpecification &specification = WindowSpecification());
    ~Window();

    void Create();
    void Destroy();

    bool ShouldClose() const;

  private:
    WindowSpecification m_Specification;
  };
}