#pragma once

#include "Window.h"
#include "Layer.h"

#include <vector>

namespace VoltR
{
  struct ApplicationSpecification
  {
    std::string Name = "Volt-Raylib Application";
    WindowSpecification WindowSpec;
  };

  class Application
  {
  public:
    Application(const ApplicationSpecification &specification = ApplicationSpecification());
    ~Application();

    void Run();
    void Stop();

    template <typename TLayer>
      requires(std::is_base_of_v<Layer, TLayer>)
    void PushLayer()
    {
      m_LayerStack.push_back(std::make_unique<TLayer>());
    }

    template <typename TLayer>
      requires(std::is_base_of_v<Layer, TLayer>)
    TLayer *GetLayer()
    {
      for (const auto &layer : m_LayerStack)
      {
        if (auto casted = dynamic_cast<TLayer *>(layer.get()))
          return casted;
      }
      return nullptr;
    }

    std::shared_ptr<Window> GetWindow() const { return m_Window; }

    static Application &Get();

  private:
    ApplicationSpecification m_Specification;
    std::shared_ptr<Window> m_Window;
    bool m_Running = false;

    std::vector<std::unique_ptr<Layer>> m_LayerStack;

    friend class Layer;
  };
}