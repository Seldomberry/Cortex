/*
                                   )
                                  (.)
                                  .|.
                                  | |
                              _.--| |--._
                           .-';  ;`-'& ; `&.
                          \   &  ;    &   &_/
                           |"""---...---"""|
                           \ | | | | | | | /
                            `---.|.|.|.---'

 * This file is generated by bake.lang.c for your convenience. Headers of
 * dependencies will automatically show up in this file. Include prebake.h
 * in your main project file. Do not edit! */

#ifndef CORTO_PREBAKED_H
#define CORTO_PREBAKED_H

/* Headers of public dependencies */
#include <bake.util>

/* Headers of private dependencies */
#ifdef CORTO_IMPL
/* No dependencies */
#endif

/* Convenience macro for exporting symbols */
#if CORTO_IMPL && defined _MSC_VER
#define CORTO_EXPORT __declspec(dllexport)
#elif CORTO_IMPL
#define CORTO_EXPORT __attribute__((__visibility__("default")))
#elif defined _MSC_VER
#define CORTO_EXPORT __declspec(dllimport)
#else
#define CORTO_EXPORT
#endif

#endif

