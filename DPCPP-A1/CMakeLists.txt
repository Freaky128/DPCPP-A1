# CMakeList.txt : CMake project for DPCPP-A1, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (DPCPP-A1 "main.cpp"  "Game.h"  "MoonManager.h" "Item.h" "AbstractMoon.h" "Moon.h" "CorpMoon.h" "Game.cpp"    "ItemManager.h" "ItemManager.cpp" "MoonManager.cpp" "util.h" "util.cpp"  "Moon.cpp" "CorpMoon.cpp" "PaidMoon.h" "PaidMoon.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DPCPP-A1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
