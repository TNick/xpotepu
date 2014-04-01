/* ========================================================================= */
/* ------------------------------------------------------------------------- */
/*!
  \file			logic.c
  \date			March 2014
  \author		Nicu Tofan

  \brief		implementation of a logic


*/
/* ------------------------------------------------------------------------- */
/* ========================================================================= */
//
//
//
//
/*  INCLUDES    ------------------------------------------------------------ */

#include "logic.h"
#include "template.h"

#include <string.h>

/*  INCLUDES    ============================================================ */
//
//
//
//
/*  DEFINITIONS    --------------------------------------------------------- */

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

LOGIC_EXPORT
void xpotepu_logic_init (xpotepu_logic_t *xpotepu_logic)
{
    memset (xpotepu_logic, 0, sizeof(xpotepu_logic_t));
}

LOGIC_EXPORT
void xpotepu_logic_end (xpotepu_logic_t *item)
{
    // free all templates
    logic_template_t * iter_template = item->tpl_;
    while (iter_template != NULL) {
        logic_template_free (&iter_template);
        iter_template = item->tpl_;
    }
    
    memset (item, 0, sizeof(xpotepu_logic_t));
}

LOGIC_EXPORT
int xpotepu_logic_foreach_template(
        xpotepu_logic_t *item, 
        xpotepu_logic_templates_kb kb,
        void *user)
{
    int ret = 0;
    logic_template_t * iter_template = item->tpl_;
    while (iter_template != NULL) {
        ret = kb(iter_template, user);
        if (ret != 0) break;
        iter_template = iter_template->next_;
    }
    return ret;
}

/*  FUNCTIONS    =========================================================== */
//
//
//
//
/* ------------------------------------------------------------------------- */
/* ========================================================================= */



