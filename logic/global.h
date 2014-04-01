/* ========================================================================= */
/* ------------------------------------------------------------------------- */
/*!
  \file			global.h
  \date			September 2013
  \author		TNick
  
*//*


 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Please read COPYING and README files in root folder
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
/* ------------------------------------------------------------------------- */
/* ========================================================================= */
#ifndef global_h_INCLUDE
#define global_h_INCLUDE
//
//
//
//
/*  INCLUDES    ------------------------------------------------------------ */

// generated on the fly from config.h.in by CMake
#include <xpotepu/config.h>
#include <assert.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/*  INCLUDES    ============================================================ */
//
//
//
//
/*  DEFINITIONS    --------------------------------------------------------- */

/// borrowed from zmq
#if defined WIN32
#   if defined XPOTEPU_LOGIC_STATIC
#       define LOGIC_EXPORT
#   elif defined XPOTEPU_LOGIC_SHARED
#       define LOGIC_EXPORT __declspec(dllexport)
#   else
#       define LOGIC_EXPORT /*__declspec(dllimport)*/
#   endif
#else
#   if defined __SUNPRO_C  || defined __SUNPRO_CC
#       define LOGIC_EXPORT __global
#   elif (defined __GNUC__ && __GNUC__ >= 4) || defined __INTEL_COMPILER
#       define LOGIC_EXPORT __attribute__ ((visibility("default")))
#   else
#       define LOGIC_EXPORT
#   endif
#endif

#if __STDC_VERSION__ < 199901L
#	if __GNUC__ >= 2
#		define __func__ __FUNCTION__
#	else
#		define __func__ "<unknown>"
#	endif
#endif

typedef enum _func_exit_code_t {
    FUNC_OK,
    FUNC_GENERIC_ERROR,
    FUNC_MEMORY_ERROR,
    FUNC_BAD_INPUT
} func_exit_code_t;

#ifndef NULL
#define NULL ((void*)0)
#endif

//! our assert
#ifdef _DEBUG
#  define DBG_ASSERT(a) if (!(a)) {asm volatile ("int $3\n");} // assert(a)
#else
#  define DBG_ASSERT(a)
#endif


//! simple pointer addition
#define PTR_ADD(p,i) ( ((char*)p) + i )

//! offset of a pointer relative to another pointer
#define PTR_OFF(pbase,prelative) ( ((char*)prelative) - ((char*)pbase) )

//! round to even pointer size
#define ROUND_TO_PTR(sz) ( sizeof(void*) - ( sz % sizeof(void*) ) )

#define VAR_UNUSED(expr) do { (void)(expr); } while (0)


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
#endif // global_h_INCLUDE
