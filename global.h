/* GLOBAL.H - RSAREF types and constants
 */

/* PROTOTYPES should be set to one if and only if the compiler supports
  function argument prototyping.
The following makes PROTOTYPES default to 0 if it has not already
  been defined with C compiler flags.
 */

#include <stdint.h>

/* wrong definitions of types will cause the code to work incorrectly */

/* POINTER defines a generic pointer type */
typedef unsigned char * POINTER;

/* UINT2 defines a two byte word */
typedef uint16_t UINT2;

/* UINT4 defines a four byte word */
typedef uint32_t UINT4;
