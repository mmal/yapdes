/**
 * @file   ODE_trigger_bundle.h
 * @author Pawel Biernat <pawel.biernat@gmail.com>
 * @date   Wed Mar 16 17:04:32 2011
 *
 * @brief Trigger bundle to consistently manage triggers loaded to
 * ODE_module.
 *
 *
 */
#ifndef _ODE_TRIGGER_BUNDLE_H_
#define _ODE_TRIGGER_BUNDLE_H_

#include "common.h"
#include "solver/ODE_module.h"
#include "solver/ODE_trigger.h"

/**
 * Structure analogous to ODE_module_bundle.
 *
 */

struct ODE_trigger_bundle
{
  /**@name temporary data format

     @todo to be replaced by some general structure (for example list)

     @{*/
  ODE_trigger ** triggers;	/**< Table of pointers to
				   ODE_trigger */

  ODE_uint trig_num;		/**< number of loaded triggers */

  ODE_uint max_trigs;		/**< maximum number of triggers to load
				   (corresponding to a memory size) */

  /**@}*/
  /* ODE_uint run_mode;		/\**< a switch to change global */
  /* 				   behaviour of triggers *\/ */
  ODE_module * module;		/**< Pointer to a parent module */
};


/**
 * Function similar to ODE_module_bundle_init()
 *
 * @param m
 * @param size
 *
 * @return
 */
ODE_trigger_bundle * ODE_trigger_bundle_init( ODE_module * m, ODE_uint size);

/**
 * Function similar to ODE_module_bundle_add_module()
 *
 * @param tb
 * @param t
 */
void ODE_trigger_bundle_add_trigger( ODE_trigger_bundle * tb, ODE_trigger * t );

/**
 * Function calling ODE_trigger_start() for every trigger in a bundle.
 *
 * @param tb
 */
void ODE_trigger_bundle_start( ODE_trigger_bundle * tb );

/**
 * Function calling ODE_trigger_stop() for every trigger in a bundle.
 *
 * @param tb
 */
void ODE_trigger_bundle_stop( ODE_trigger_bundle * tb );

/**
 * Calls ODE_trigger_test() for every trigger in a bundle.
 *
 * @param tb
 *
 * @retval 0 one of the triggers tests passed
 * @retval 1 non of the tests passed
 */
ODE_uint ODE_trigger_bundle_test( ODE_trigger_bundle * tb );

/**
 * Function similar to ODE_module_bundle_free().
 *
 * @attention It has to be run after ODE_trigger_bundle_stop().
 *
 * @param tb
 */
void ODE_trigger_bundle_free( ODE_trigger_bundle * tb );

/**
 * Function to count triggers in a given trigger_bundle
 *
 * @param tb
 *
 * @return Number of triggers added to tb
 */
ODE_uint ODE_trigger_bundle_count( ODE_trigger_bundle * tb );



#endif /* _ODE_TRIGGER_BUNDLE_H_ */
