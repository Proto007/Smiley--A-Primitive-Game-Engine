#include "pch.h"
#include "Events.h"

namespace Smiley {
	KeyPressedEvent::KeyPressedEvent( int keyCode ):mKeyCode(keyCode){

	}
	int KeyPressedEvent::GetKeyCode() const {
		return mKeyCode;
	}
}