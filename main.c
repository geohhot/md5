
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "md5.h"

/* code from RFC 1321 */
/* Copyright (C) 1990-2, RSA Data Security, Inc. Created 1990. All */
/* rights reserved. */

static void MDPrint (digest)
unsigned char digest[16];
{
  unsigned int i;

  for (i = 0; i < 16; i++)
	printf ("%02x", digest[i]);
}

static void MDString (string)
char *string;
{
  MD5_CTX context;
  unsigned char digest[16];
  unsigned int len = strlen (string);

  printf ("len: %u\n", len);
  
  MD5Init (&context);
  MD5Update (&context, string, len);
  MD5Final (digest, &context);

  printf ("MD%d (\"%s\") = ", 5, string);
  MDPrint (digest);
  printf ("\n");
}

static void MDTestSuite ()
{
  MDString ("");
  MDString ("a");
  MDString ("abc");
  MDString ("message digest");
  MDString ("abcdefghijklmnopqrstuvwxyz");
  MDString
 ("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
  MDString
 ("1234567890123456789012345678901234567890\
1234567890123456789012345678901234567890");
}

int main (void) {

  #define TEST_STR "The quick brown fox jumps over the lazy dog"
  char *test = TEST_STR;
  uint8_t len = strlen (TEST_STR);
  uint8_t final_digest[16];
  MD5_CTX ctx;  

  /* usage example */
  MD5Init (&ctx);
  MD5Update (&ctx, test, len);
  MD5Final (final_digest, &ctx);
  printf ("hash was: ");
  MDPrint (final_digest);
  /* for (uint8_t i =0; i< 16; ++i) */
  /* 	printf ("%02x", final_digest[i]); */
  
  printf ("\n" "expccted: 9e107d9d372bb6826bd81d3542a419d6\n");
  
  /* MDString (TEST_STR); */
  /* MDTestSuite (); */
  
  return 0;
}
