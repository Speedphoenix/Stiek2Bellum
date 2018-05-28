#ifndef DEBUGNERRORS_H_INCLUDED
#define DEBUGNERRORS_H_INCLUDED


#include <iostream>

#define E(x) {std::cerr << std::endl << #x ": " << x << std::endl;}
#define ES(x) {std::cerr << std::endl << x << std::endl;}


#endif //DEBUGNERRORS_H_INCLUDED

