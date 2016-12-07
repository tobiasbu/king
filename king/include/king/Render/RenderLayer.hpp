

#ifndef KING_RENDERLAYER_HPP
#define KING_RENDERLAYER_HPP

#include <king/Entity/Renderer.hpp>

#include <string>
#include <vector>

namespace king {

	namespace system {
		class RenderQueue;
	}

	class RenderLayer {

		friend class system::RenderQueue;

	private:

		bool _depthOrderDirty = false;

		std::string _name;

		std::vector<Renderer *> _renderers;

		void onRender();
		void sortDepth();

		/*inline bool compareDepth(const Renderer &a, const Renderer &b)
		{
			return a._depthOrder < b._depthOrder;
		}*/

		

	public:
		RenderLayer(std::string name);

		std::string getName();
		void addRenderer(Renderer *);
		void removeRenderer(Renderer *);
		void setDepthOrderDirty(bool flag);
		

	};

}

#endif