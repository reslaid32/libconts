#ifndef RESULT_H
#define RESULT_H

#include <stdint.h>

#define ContsResultFailure (-1)
#define ContsResultSuccess ( 0)

typedef int8_t ContsResultType;

#define ContsResultIsSuccess(Result) ( (Result) == ContsResultSuccess )
#define ContsResultIsFailed(Result) ( (Result) != ContsResultSuccess )

#endif // RESULT_H