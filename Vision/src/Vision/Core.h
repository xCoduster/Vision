#pragma once

#ifdef VI_PLATFORM_WINDOWS
#else
#error Vision only supports Windows!
#endif

#ifdef VI_DEBUG
#define VI_ENABLE_ASSERTS
#endif

#ifdef VI_ENABLE_ASSERTS
#define VI_ASSERT(x, ...) { if(!(x)) { VI_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define VI_CORE_ASSERT(x, ...) { if(!(x)) { VI_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define VI_ASSERT(x, ...)
#define VI_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)