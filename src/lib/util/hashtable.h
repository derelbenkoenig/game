#ifndef INCLUDED_HASHTABLE_H
#define INCLUDED_HASHTABLE_H

#include "typed_pointer.h"

typedef struct __hashtable Hashtable;

Hashtable* hashtable_create(unsigned long table_size);
void hashtable_destroy(Hashtable *table, void (*dtor)(TypedPointer *));

/**
 * Insert into hashtable.
 * @return previous value for that key, if any
 */
TypedPointer hashtable_put(Hashtable *table, const char *key, TypedPointer value);

/**
 * Get from hashtable. 
 */
TypedPointer hashtable_get(Hashtable *table, const char *key);

/**
 * Delete from hashtable.
 */
TypedPointer hashtable_delete(Hashtable *table, const char *key);

#endif
