/* { dg-do compile { target powerpc*-*-* } } */
/* { dg-options "-maltivec" } */

#include <altivec.h>

extern void preansi();

typedef void (*pvecfunc) ();

void foo(pvecfunc pvf) {
   vector int v = (vector int){1, 2, 3, 4};
#ifndef __LP64__
   preansi (4, 4.0, v); /* { dg-error "AltiVec argument passed to unprototyped function" } */
   (*pvf)  (4, 4.0, v); /* { dg-error "AltiVec argument passed to unprototyped function" } */
#endif /* __LP64__ */
}

