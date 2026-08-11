#pragma once /// Copyright 2026 viraltaco <https://viraltaco.com>
#ifndef COM_VIRALTACO_PRECONDTION_H
#define COM_VIRALTACO_PRECONDTION_H "com.viraltaco.precondition.h v" "0.1.1"

#include <stdio.h>  // fprintf
#include <stdlib.h> // abort

void vt_precondition_impl( bool const           pre_condition
                         , char const* restrict condition_string
                         , char const* restrict file
                         , char const* restrict func
                         , unsigned const       line) {
  if (pre_condition) {
    return;
  } else {
    fprintf( stderr
           , "Failure for precondition \"%s\" in function %s\nIn file '%s' on line %d.\n"
           , condition_string, func, file, line)
           ;
    abort();
  }
} // vt_precondition_impl

#ifndef vt_precondition
#  ifndef __clang__
#  define vt_precondition(COND) vt_precondition_impl((COND), (#COND), __FILE__, __PRETTY_FUNCTION__, __LINE__)
#  else // __clang__ defined
#  define vt_precondition(COND) vt_precondition_impl((COND), (#COND), __FILE_NAME__, __PRETTY_FUNCTION__, __LINE__)
#  endif // ndef __clang__
#endif // ndef vt_precondition

#endif // ndef COM_VIRALTACO_PRECONDITION_H
