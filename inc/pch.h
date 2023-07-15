#pragma once

/** precompiled header **/

#include <iostream>

#include "helper.h"

#ifdef NDEBUG
#define VERBOSE(x) {}
#else
#define VERBOSE(x) { (x); }
#endif
