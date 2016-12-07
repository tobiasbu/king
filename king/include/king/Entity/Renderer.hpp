
#ifndef KING_RENDERER_HPP
#define KING_RENDERER_HPP

#include <king/Entity/Component.hpp>

namespace king {

	class RenderLayer;

	class Renderer : public Component {

	friend class RenderLayer;

	private:
		
		/// Member data

		// internal variable
		int _rendererIndex = 0;


		int _depthOrder = 0;
		RenderLayer * _layer = nullptr;

		// internal

	protected:

		virtual void render() = 0;

	public:

		Renderer();

		/// Setters

		void setLayer(std::string);
		void setDepth(int depth);

		/// Getters

	

		RenderLayer * getLayer();
		std::string getLayerName();
		int getDepth();

		bool operator >(const Renderer& other) const
		{
			return (_depthOrder > other._depthOrder);
		}



	};

}

#endif