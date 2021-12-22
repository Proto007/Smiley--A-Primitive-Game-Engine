#pragma once

#ifdef SMILEY_WINDOWS
	#ifdef SMILEY_LIB
		#define SMILEY_API __declspec(dllexport)
	#else
		#define SMILEY_API __declspec(dllimport)
	#endif
#else
	#define SMILEY_API
#endif

#ifdef SMILEY_DEBUG
	#define SMILEY_LOG(x) std::cout<<x<<std::endl;
#else
	#define SMILEY_LOG(x)
#endif
