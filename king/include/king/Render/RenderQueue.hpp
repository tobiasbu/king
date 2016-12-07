
#ifndef KING_RENDERQUEUE_HPP
#define KING_RENDERQUEUE_HPP

#include <vector>
#include <map>
#include <string>

#include <king/Render/RenderLayer.hpp>
#include <king/Others/Singleton.hpp>
#include <king/Others/NonCopyable.hpp>

namespace king {

	namespace system {

		class RenderQueue : public Singleton<RenderQueue>, NonCopyable {

		private:

			std::vector<RenderLayer *> _layers;
			std::map<std::string, int> _layersByName;

			void swapRendererTo();
			

			

		public:

			RenderQueue();

			RenderLayer * getLayer(int index);
			RenderLayer * getLayer(std::string name);

			RenderLayer * addLayer(std::string);			
			void removeLayer(std::string);
			void swapLayer(std::string, std::string);
			void onRender();

		};
		
	}

}

#endif