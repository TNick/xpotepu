/* ========================================================================= */
/* ------------------------------------------------------------------------- */
/*!
  \file			template.h
  \date			March 2014
  \author		Nicu Tofan

*/
/* ------------------------------------------------------------------------- */
/* ========================================================================= */
#ifndef XPOTEPU_logic_template_h_INCLUDE
#define XPOTEPU_logic_template_h_INCLUDE
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



struct _xpotepu_logic_t;

//! a template
///
typedef struct _logic_template_t {
    struct _xpotepu_logic_t *       parent_;    /**< parent structure */
    struct _logic_template_t *      next_;      /**< next in chain */
} logic_template_t;

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

//! initialize a template
LOGIC_EXPORT func_exit_code_t
logic_template_new (struct _xpotepu_logic_t * parent, logic_template_t **tpl);

//! terminate a template
LOGIC_EXPORT void
logic_template_free (logic_template_t **tpl);

//! read template characteristics from a file
LOGIC_EXPORT func_exit_code_t
logic_template_from_cfg(
        logic_template_t * tpl,
        const char * file);



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
#endif // XPOTEPU_logic_template_h_INCLUDE
