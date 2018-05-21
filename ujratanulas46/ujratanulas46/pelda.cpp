#include "stdafx.h"
#include <iostream>

// adott a következő funkció prototype: int printData();

// alakítsd át az int return értéket egy typedef-é, a typedef kulcsszóval, aminek a neve error_t;

int printData();
typedef int error_t;
error_t printData();

// ugyanaz, de c++11 alapján, using kulcsszóval.

int printData();
using error_t = int;
error_t printData();