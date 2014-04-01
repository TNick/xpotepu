/* ========================================================================= */
/* ------------------------------------------------------------------------- */
//
//
//
//
/*  INCLUDES    ------------------------------------------------------------ */

#include <xpotepu/template.h>

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

logic_template_t * create_test_template();

//! loads test_template_log_full()
logic_template_t * create_test_template_with_log_loaded();

void add_n_templates (xpotepu_logic_t * parent, int n);

const char * test_template_config();

//! formatted log so that it supports a binary compare against original
const char * test_template_log();

//! full log of a session with two beacons
const char * test_template_log_full();
void test_template_log_full_results(int index, double * x, double * y);

//! result of a logic_template_save_paths()
const char * test_template_paths_file();

void compare_two_texts(const char * t1, const char * t2);

/*  FUNCTIONS    =========================================================== */
//
//
//
//
/* ------------------------------------------------------------------------- */
/* ========================================================================= */

