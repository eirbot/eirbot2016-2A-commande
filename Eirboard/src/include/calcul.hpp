/*****************************************************/
/*                Calcul Architecture                */
/*                   STM32F429ZI                     */
/*                                                   */
/*****************************************************/

#pragma once

// Convert a binary string to a binary int
static inline u32 s2bin(const char *s);

static inline u32 bitsCount (u32 number);

static inline u32 dataParity (u32 data);