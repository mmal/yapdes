#ifndef _ODE_ERROR_H_
#define _ODE_ERROR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ODE_error ( const char * msg, const char * file, int line, const int errno );

#define _ODE_ERROR(msg,errno)                   \
       do { \
           ODE_error (msg, __FILE__, __LINE__, errno) ; \
       } while (0)




#endif /* _ODE_ERROR_H_ */


