


#ifndef KING_COLOR_HPP
#define KING_COLOR_HPP

#include <string>

namespace king {

	struct Color {


		// Data
		float r, g, b, a;
		
		// Constructors
		Color();
		Color(float R, float G, float B, float A);

		// Functions
		void setRGB(int r, int g, int b, int a);
		std::string toString();

		// Operators
		bool operator==(Color A) const;

		// Static Functions
		static Color makeFromRGBColor(int r, int g, int b, int a);
		static Color random(Color A, Color B);
		static Color lerp(Color from, Color to, float t);

		// Static variables
		const static Color white;
		const static Color black;
		const static Color grey;
		const static Color transparent;
		const static Color red;
		const static Color green;
		const static Color blue;
		const static Color yellow;
		const static Color cyan;
		const static Color magenta;
	


	};

}

//Color Color::white(1, 1, 1, 1);

#endif