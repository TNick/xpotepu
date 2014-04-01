/* ========================================================================= */
/* ------------------------------------------------------------------------- */
//
//
//
//
/*  INCLUDES    ------------------------------------------------------------ */

#include <xpotepu/global.h>


#include "logic_helper.h"
#include "template_helper.h"
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

static inline const char *
get_temp_file(const char * name)
{
    size_t sz_n = strlen(name);
    size_t sz_tmp;

#if defined WIN32
    sz_tmp = strlen("./");
#else
    sz_tmp = strlen("/tmp/");
#endif

    size_t sz_tot = sz_n + sz_tmp + 1;
    char * retb = (char*)malloc(sz_tot);
#if defined WIN32
    sprintf(retb, "./%s", name);
#else
    sprintf(retb, "/tmp/%s", name);
#endif

    return retb;
}

static inline const char *
get_text(const char * file_path)
{
    FILE * f = NULL;
    size_t fsz;
    char * file_content = NULL;

    f = fopen (file_path, "rb");
    if (f == NULL) {
        return NULL;
    }

    fseek (f, 0, SEEK_END);
    fsz = ftell (f);
    fseek (f, 0, SEEK_SET);

    // allocate a buffer large enough
    file_content = (char*) malloc (fsz+1);
    if (file_content != NULL) {
        size_t fsz_read = fread (file_content, fsz, 1, f);
        if (1 != fsz_read) {
            free (file_content);
            file_content = NULL;
        }
        file_content[fsz] = 0;
    }
    fclose(f);

    return file_content;
}

/*  FUNCTIONS    =========================================================== */
//
//
//
//
/* ------------------------------------------------------------------------- */
/* ========================================================================= */

