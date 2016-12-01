
#include <ostream>

namespace king {

	class Log {

	private:
		bool _active = true;

	public:
		Log();
		void setActive(bool);
		bool isActive();
		virtual std::ostream& GetStream(void) = 0;
		virtual void LogMessage(const char* theMessage) = 0;

	};

}