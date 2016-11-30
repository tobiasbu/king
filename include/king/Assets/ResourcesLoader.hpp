
#include <string>
#include <list>

#include "Singleton.hpp"
#include "AsyncRequest.hpp"
#include "AssetManager.hpp"

namespace king {

	namespace adv {

		class ResourcesLoader : public NonCopyable, Singleton<ResourcesLoader> {

		private:

			bool __sceneMarkedAsAsync = false;
			AssetManager * _assetManager;
			void _asyncLoad();
			std::list<AsyncRequest *> __asyncRequestList;

		public:

			void registerAssetManager(AssetManager * assetManager) {
				_assetManager = assetManager;
			}

			/*template<typename T>
			T * static loadAsset(std::string path) {

				//adv::KING_ASSETMANAGER
				//__sceneMarkedAsAsync = true;
			}*/

/*			static bool test() {
				return __sceneMarkedAsAsync;//(_assetManager == nullptr) ? true : false;
			}*/


		};

	}

}