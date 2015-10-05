#ifndef GENETICS_H
#define GENETICS_H

#include <stdlib.h>
#include <vector>
#include "chromo.h"

template <typename T>
chromosome_t<T> roulette_selection(typename std::vector< chromosome_t<T> > *, int);

#endif