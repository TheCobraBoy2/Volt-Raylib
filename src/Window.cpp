#include <VoltRayLib/Window.h>

#include <raylib.h>

#include <assert.h>

namespace VoltR
{
  Window::Window(const WindowSpecification &specification) : m_Specification(specification) {}
  Window::~Window()
  {
    Destroy();
  }

  void Window::Create()
  {
    InitWindow(m_Specification.Width, m_Specification.Height, m_Specification.Title.c_str());
  }

  void Window::Destroy()
  {
    CloseWindow();
  }

  bool Window::ShouldClose() const
  {
    return WindowShouldClose() != 0;
  }
}