#pragma once
#include "SmileyUtils.h"
namespace Smiley {
	class SMILEY_API KeyPressedEvent {
	public:
		KeyPressedEvent( int keyCode );
		int GetKeyCode() const;
	private:
		int mKeyCode{ -1 };
	};
}