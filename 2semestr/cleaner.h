#pragma once
#include <iostream>

// режимы
#define DEFAULT 0
#define DISABLED 1
#define WARNING_ONLY 2
#define FORCE_DISABLED 3


#ifndef CLEANER_LOG
#define CLEANER_LOG DEFAULT
#endif

#if CLEANER_LOG == DEFAULT
    // default

#elif CLEANER_LOG == DISABLED
    #pragma message("output disabled")
    #warning "Outdated library, visit github.com/cleaner2"

#elif CLEANER_LOG == WARNING_ONLY
    #warning "Outdated library, visit github.com/cleaner2"

#elif CLEANER_LOG == FORCE_DISABLED
    #pragma message("Output forced to disabled")

#else
    #error "Unknown CLEANER_LOG value"
#endif