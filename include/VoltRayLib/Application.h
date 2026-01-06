#pragma once

#include "Window.h"
#include "Layer.h"

#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <type_traits>

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
      requires std::is_base_of_v<Layer, TLayer>
    TLayer &PushLayer()
    {
      auto layer = std::make_unique<TLayer>();
      TLayer &ref = *layer;

      m_LayerStack.emplace(
          m_LayerStack.begin() + m_InsertIndex,
          std::move(layer));

      m_InsertIndex++;
      ref.OnAttach();
      return ref;
    }

    template <typename TOverlay>
      requires std::is_base_of_v<Layer, TOverlay>
    TOverlay &PushOverlay()
    {
      auto overlay = std::make_unique<TOverlay>();
      TOverlay &ref = *overlay;

      m_LayerStack.emplace_back(std::move(overlay));
      ref.OnAttach();

      return ref;
    }

    template <typename TLayer>
      requires std::is_base_of_v<Layer, TLayer>
    void PopLayer()
    {
      for (auto it = m_LayerStack.begin();
           it != m_LayerStack.begin() + m_InsertIndex;
           ++it)
      {
        if (dynamic_cast<TLayer *>(it->get()))
        {
          (*it)->OnDetach();
          m_LayerStack.erase(it);
          m_InsertIndex--;
          return;
        }
      }
    }

    template <typename TOverlay>
      requires std::is_base_of_v<Layer, TOverlay>
    void PopOverlay()
    {
      for (auto it = m_LayerStack.begin() + m_InsertIndex;
           it != m_LayerStack.end();
           ++it)
      {
        if (dynamic_cast<TOverlay *>(it->get()))
        {
          (*it)->OnDetach();
          m_LayerStack.erase(it);
          return;
        }
      }
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

    uint32_t m_InsertIndex = 0;

    std::vector<std::unique_ptr<Layer>> m_LayerStack;

    friend class Layer;
  };
}