# CS50 Lab 3
## CS50 Summer 2021
## Callie Moody

### Set

A `hashtable` is an unordered collection of _items_.
The `hashtable` starts empty, grows as the caller adds one _item_ at a time.

### Usage

The *hashtable* module, defined in `hashtable.h` and implemented in `hashtable.c`, implements a set of String keys pointing to `void*`, and exports the following functions:

```c

hashtable_t *hashtable_new(const int num_slots);

bool hashtable_insert(hashtable_t *ht, const char *key, void *item);

void *hashtable_find(hashtable_t *ht, const char *key);

void hashtable_print(hashtable_t *ht, FILE *fp, 
                     void (*itemprint)(FILE *fp, const char *key, void *item));


void hashtable_iterate(hashtable_t *ht, void *arg,
                       void (*itemfunc)(void *arg, const char *key, void *item) );


void hashtable_delete(hashtable_t *ht, void (*itemdelete)(void *item) );

```

### Implementation

We implement this hashtable as an array.
The *hashtable* itself is represented as a `struct hashtable`.

Each entry in the array is a `struct set`, a type defined in set.h.

Each setnode includes a pointer to the `set_t** array`, and the number of slots in the array.

To insert a new item in the set we create a new setnode to hold the `item`, and insert it at the end of the set it belongs in.

### Assumptions

None other than given in the assignment

### Files

* `Makefile` - compilation procedure
* `hashtable.h` - the interface
* `hashtable.c` - the implementation
* `hashtest.c` - unit test driver
* `test.keys` - test data
* `TESTING.md` - testing results results

### Compilation

To compile, simply `make hashtable.o`.

### Testing

The `hashtest.c` program reads lines from stdin and stuffs them into a hashtable.
It tests a few error and edge cases.
This test is somewhat minimal.
