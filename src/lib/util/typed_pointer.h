#ifndef INCLUDED_TYPED_POINTER_H
#define INCLUDED_TYPED_POINTER_H

/*
 * Declarations for "typed pointers". Just a void pointer and a type, basically does a type-safety
 * check at runtime when you attempt to cast and dereference the contained pointer.
 */

// TODO consider having a top-level include file to cut down on boilerplate
#include <stdlib.h>
#include <string.h>
// TODO consider making my own assert?
#include <assert.h>

typedef struct __typed_pointer TypedPointer;
struct __typed_pointer {
	void *data;
	// MUST always be a string literal created from stringifying macro
	const char *type;
};

#define TYPED_POINTER_GET(ptr, desired_type) ({ \
	assert(strcmp(ptr->type, #desired_type) == 0); \
	((desired_type) ptr->data) \
})

#define TYPED_POINTER_CREATE(value, desired_type) ({ \
	TypedPointer *s = malloc(sizeof(*s)); \
	/* so compiler will error if this type is incompatible */ \
	desired_type d = value; \
	s->data = ((void *) d); \
	s->type = #desired_type; \
	s; \
})

#define TYPED_POINTER_DESTROY(ptr) do {free (ptr);} while (0)
#endif // INCLUDED_TYPED_POINTER_H
