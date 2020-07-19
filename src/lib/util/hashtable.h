#ifndef INCLUDED_HASHTABLE_H
#define INCLUDED_HASHTABLE_H

typedef struct hashtable Hashtable;

Hashtable* hash_table_create(unsigned long table_size);
bool hash_table_insert(Hashtable* table, const char *key, TypedPointer value);
#endif
