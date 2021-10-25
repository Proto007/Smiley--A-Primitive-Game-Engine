set(SOURCE_FILES SmileyApp.cpp)

set(HEADER_FILES Smiley.h SmileyApp.h SmileyUtils.h)

add_library(smiley_lib SHARED $(SOURCE_FILES) $(HEADER_FILES))

targer_precompile_headers(smiley_lib PRIVATE pch.h)