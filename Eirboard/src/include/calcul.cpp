/*****************************************************/
/*                Calcul Architecture                */
/*                   STM32F429ZI                     */
/*                                                   */
/*****************************************************/

#include "calcul.hpp"

// Convert a binary string to a binary int
static inline u32 s2bin(const char *s)
{
    u32 i = 0;
    while (*s)
    {
        i <<= 1;
    	i += *s++ - '0';
    }
    return i;
}

static inline u32 bitsCount (u32 number)
{
    u32 count = 0;
    while (number != 0)
    {
        if (number & 1 << 1)
            count++;
        number = number >> 1;
    }
    return count;
}

static inline u32 dataParity (u32 data)
{
    return bitsCount (data) & 1;
}