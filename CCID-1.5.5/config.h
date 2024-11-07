/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* bundle directory name */
#define BUNDLE "ifd-ccid.bundle"

/* Enable Zero Length Packet patch */
/* #undef ENABLE_ZLP */

/* Define to 1 if you have the <arpa/inet.h> header file. */
#define HAVE_ARPA_INET_H 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <errno.h> header file. */
#define HAVE_ERRNO_H 1

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <libusb.h> header file. */
#define HAVE_LIBUSB_H 1

/* Define to 1 if you have the 'memcpy' function. */
#define HAVE_MEMCPY 1

/* Define to 1 if you have the 'pthread_condattr_setclock' function. */
/* #undef HAVE_PTHREAD_CONDATTR_SETCLOCK */

/* Define to 1 if you have the 'secure_getenv' function. */
/* #undef HAVE_SECURE_GETENV */

/* Define to 1 if you have the 'select' function. */
#define HAVE_SELECT 1

/* Define to 1 if you have the <stdarg.h> header file. */
#define HAVE_STDARG_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the 'strerror' function. */
#define HAVE_STRERROR 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the 'strlcat' function. */
#define HAVE_STRLCAT 1

/* Define to 1 if you have the 'strlcpy' function. */
#define HAVE_STRLCPY 1

/* Define to 1 if you have the 'strncpy' function. */
#define HAVE_STRNCPY 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <termios.h> header file. */
#define HAVE_TERMIOS_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Disable logging support */
/* #undef NO_LOG */

/* Name of package */
#define PACKAGE "ccid"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "ccid"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "ccid 1.5.5"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "ccid"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.5.5"

/* directory containing USB drivers */
#define PCSCLITE_HP_DROPDIR "/usr/local/libexec/SmartCardServices/drivers"

/* Define to 1 if all of the C89 standard headers exist (not just the ones
   required in a freestanding environment). This macro is provided for
   backward compatibility; new code need not use it. */
#define STDC_HEADERS 1

/* composite device are seen as multi-slots */
#define USE_COMPOSITE_AS_MULTISLOT 1

/* Use os_log(3) for debug */
#define USE_OS_LOG 1

/* Use syslog(3) for debug */
/* #undef USE_SYSLOG */

/* Version number of package */
#define VERSION "1.5.5"

/* Define to 1 if 'lex' declares 'yytext' as a 'char *' by default, not a
   'char[]'. */
#define YYTEXT_POINTER 1

/* Define to empty if 'const' does not conform to ANSI C. */
/* #undef const */

/* Define as 'unsigned int' if <stddef.h> doesn't define. */
/* #undef size_t */
