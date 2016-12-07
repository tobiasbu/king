


#ifndef KING_UNIQUEIDENTIFIER_HPP
#define KING_UNIQUEIDENTIFIER_HPP

#include <stack>
#include <king/Type/Types.hpp>
#include <king/Math/Random.hpp>
#include <king/Others/NonCopyable.hpp>

namespace king {

	namespace system {

		class UniqueIdentifier : public NonCopyable {

		private:

			std::stack<uint64> _unusedGUIDS;
			uint64 _GUID = Random::;

		public:

		};

	}

}

#endif