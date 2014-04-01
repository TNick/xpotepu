/* ========================================================================= */
/* ------------------------------------------------------------------------- */
/*!
  \file			logic.h
  \date			March 2014
  \author		Nicu Tofan

*/
/* ------------------------------------------------------------------------- */
/* ========================================================================= */
#ifndef XPOTEPU_logic_h_INCLUDE
#define XPOTEPU_logic_h_INCLUDE
//
//
//
//
/*  INCLUDES    ------------------------------------------------------------ */

#include <xpotepu/global.h>

#ifdef __cplusplus
extern "C" {
#endif

/*  INCLUDES    ============================================================ */
//
//
//
//
/*  DEFINITIONS    --------------------------------------------------------- */

struct _logic_template_t;

//! a logic
///
typedef struct _xpotepu_logic_t {
    struct _logic_template_t *  tpl_;
    
} xpotepu_logic_t;

/*  DEFINITIONS    ========================================================= */
//
//
//
//
/*  DATA    ---------------------------------------------------------------- */

/*  DATA    ================================================================ */
//
//
//
//
/*  FUNCTIONS    ----------------------------------------------------------- */

//! initialize a logic
LOGIC_EXPORT void
xpotepu_logic_init (xpotepu_logic_t *xpotepu_logic);

//! terminate a logic
LOGIC_EXPORT void
xpotepu_logic_end (xpotepu_logic_t *xpotepu_logic);



//! callback used to iterate in all templates
///
/// @return non-zero to terminate the loop
/// 
typedef int (*xpotepu_logic_templates_kb) (
        struct _logic_template_t * tpl,
        void * user);

//! iterate in all templates
///
/// @return non-zero if a callback terminated the loop early (the value 
/// returned by callback is returned), or 0 for ok
LOGIC_EXPORT int
xpotepu_logic_foreach_template (
        xpotepu_logic_t *item,
        xpotepu_logic_templates_kb kb,
        void * user);



/*  FUNCTIONS    =========================================================== */
//
//
//
//
/* ------------------------------------------------------------------------- */
/* ========================================================================= */
#ifdef __cplusplus
}
#endif
#endif // XPOTEPU_logic_h_INCLUDE
