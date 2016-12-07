
#include <king/Entity/Renderer.hpp>
#include <king/Render/RenderLayer.hpp>
#include <king/Render/RenderQueue.hpp>

namespace king {


	Renderer::Renderer() {

		setLayer("Default");

	}

	void Renderer::setLayer(std::string name) {

		if (_layer == nullptr) {
			_layer = system::RenderQueue::getInstance().getLayer(0);
			_layer->addRenderer(this);
		}


		if (_layer->getName() != name) {

			RenderLayer * toLayer = system::RenderQueue::getInstance().getLayer(name);

			if (toLayer != nullptr) {
				_layer->removeRenderer(this);
				toLayer->addRenderer(this);
				_layer = toLayer;
				
			} 


		}

	}


	void Renderer::setDepth(int depth) {

		if (_depthOrder != depth) {

			_depthOrder = depth;
			_layer->setDepthOrderDirty(true);

		}

	}

	RenderLayer * Renderer::getLayer() {

		return _layer;

	}

	std::string Renderer::getLayerName() {

		return _layer->getName();

	}

	int Renderer::getDepth() {

		return _depthOrder;

	}

}