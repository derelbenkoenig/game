#include <string.h>
#include "hashtable.h"

typedef struct {
	char *key;
	long hashed_key; // to know how many consecutive entries are a collision I guess?
	int is_deleted; // you need this to use "open addressing"
	TypedPointer value;
} HashtableEntry;

struct __hashtable {
	long size;
	HashtableEntry table[];
};

Hashtable* hashtable_create(unsigned long table_size)
{
	// TODO this is theoretically sometimes more memory than you need to allocalte
	// for the struct with flexible array member
	Hashtable *hashtable = calloc(1, sizeof(*hashtable) + table_size * sizeof(HashtableEntry));
	hashtable->size = table_size;
	return hashtable;
}

void hashtable_destroy(Hashtable *table, void (*dtor)(TypedPointer *))
{

}

/**
 * Insert into hashtable.
 * @return previous value for that key, if any
 */
TypedPointer hashtable_put(Hashtable *table, const char *key, TypedPointer value)
{

}

/**
 * Get from hashtable. 
 */
TypedPointer hashtable_get(Hashtable *table, const char *key)
{

}
