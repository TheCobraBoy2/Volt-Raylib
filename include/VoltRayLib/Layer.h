#pragma once

#include <memory>

namespace VoltR
{
  class Layer
  {
  public:
    virtual ~Layer() = default;

    virtual void OnUpdate(float dt) {}
    virtual void OnRender() {}

    virtual void OnAttach() {};
    virtual void OnDetach() {};

    template <std::derived_from<Layer> T, typename... Args>
    void TransitionTo(Args &&...args)
    {
      QueneTransition(std::move(std::make_unique<T>(std::forward<Args>(args)...)));
    }

  private:
    void QueneTransition(std::unique_ptr<Layer> layer);
  };
}