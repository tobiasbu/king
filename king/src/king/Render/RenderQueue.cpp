
#include <king/Render/RenderQueue.hpp>

#include <iostream>
#include <assert.h>

namespace king {

	namespace system {

		RenderQueue::RenderQueue() {

			addLayer("Default");

		}

		RenderLayer * RenderQueue::getLayer(int index) {

			assert(index >= 0 && index < _layers.size());

			return _layers[index];

		}

		RenderLayer * RenderQueue::getLayer(std::string name) {

			auto found = _layersByName.find(name);
			
			if (found != _layersByName.end())
				return _layers[found->second];
			else
				return nullptr;

		}

		RenderLayer * RenderQueue::addLayer(std::string name) {

			RenderLayer * layer = new RenderLayer(name);

			_layersByName.insert(std::make_pair(name, _layers.size()));

			_layers.push_back(layer);

			

			return layer;

		}

		void RenderQueue::removeLayer(std::string name) {

			if (name == "Default") {
				std::cerr << "King::RenderQueue: You can't remove the Default Layer" << std::endl;
				return;
			}

			auto found = _layersByName.find(name);
		
			if (found != _layersByName.end()) {
				RenderLayer * l = _layers[found->second];
				delete l;
				_layers.erase(_layers.begin() + found->second);
			}
				
		}

		void RenderQueue::swapLayer(std::string to, std::string from) {


		}

		void  RenderQueue::onRender() {

			for (int i = 0; i < _layers.size(); i++) {

				_layers[i]->onRender();

			}

		}

	}

}