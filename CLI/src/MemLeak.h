#pragma once

#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#define _CRTDBG_MAP_ALLOC

#include <cstdlib>
#include <crtdbg.h>