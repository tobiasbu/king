
#include <king/Render/RenderLayer.hpp>
#include <algorithm>

namespace king {

	RenderLayer::RenderLayer(std::string name) {

		_name = name;

	}

	void RenderLayer::addRenderer(Renderer * rend) {

		rend->_rendererIndex = _renderers.size();
		_renderers.push_back(rend);
		_depthOrderDirty = true;

	}

	void RenderLayer::removeRenderer(Renderer * rend) {

		_renderers.erase(_renderers.begin() + rend->_rendererIndex);
		

	}

	void RenderLayer::onRender() {

		if (_depthOrderDirty) {
			sortDepth();
			_depthOrderDirty = false;
		}


		for (int i = 0; i < _renderers.size(); i++) {
			_renderers[i]->render();
		}

	}

	void RenderLayer::sortDepth() {

		std::sort(_renderers.begin(), _renderers.end());

	}

	void RenderLayer::setDepthOrderDirty(bool flag) {

		_depthOrderDirty = flag;

	}

	std::string RenderLayer::getName() {

		return _name;

	}

}