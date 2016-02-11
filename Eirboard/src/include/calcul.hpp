/*****************************************************/
/*                Calcul Architecture                */
/*                   STM32F429ZI                     */
/*                                                   */
/*****************************************************/

#pragma once

#include <base/integer.hpp>

// Convert a binary string to a binary int
u32 s2bin(const char *s);

u32 bitsCount (u32 number);

u32 bitsParity (u32 data);