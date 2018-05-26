/**
 * name : debug_permission.h;
 * date : 18/4/28;
 * g++ version : 7.3.1;
 * g++ options : -O2;
 * */

#ifdef DEBUG_FLAG

#ifdef DEBUG_PERMISSION
#undef DEBUG_PERMISSION
#endif /* DEBUG_PERMISSION */

#define DEBUG_PERMISSION public
#else
#define DEBUG_PERMISSION private
#endif /* DEBUG_FLAG */
