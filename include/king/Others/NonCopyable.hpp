
#ifndef KING_NONCOPYABLE_HPP
#define KING_NONCOPYABLE_HPP

namespace king {

	class NonCopyable
	{
	protected:

		NonCopyable() {}

	private:


		NonCopyable(const NonCopyable&);
		NonCopyable& operator =(const NonCopyable&);
	};
}

#endif