#include "ODE_module_trigger.h"

ODE_module_trigger * ODE_module_trigger_init_common ( void )
{
  ODE_module_trigger * mt = malloc( sizeof( ODE_module_trigger ) );

  mt->run_flag = TRIG_RUN_DEFAULT; /* default run_time for trigger */

  /** \todo can be set to some useful value by default */
  mt->start = NULL;
  mt->stop = NULL;
  mt->test = NULL;
  mt->module = NULL;
  mt->data = NULL;

  return mt;
}

int ODE_module_trigger_free_common( ODE_module_trigger * tr )
{
  free( tr );
  return 0;
}
