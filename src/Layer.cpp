#include <VoltRayLib/Layer.h>
#include <VoltRayLib/Application.h>

namespace VoltR
{
  void Layer::QueneTransition(std::unique_ptr<Layer> toLayer)
  {
    auto &layerStack = Application::Get().m_LayerStack;
    for (auto &layer : layerStack)
    {
      if (layer.get() == this)
      {
        layer = std::move(toLayer);
        return;
      }
    }
  }
}