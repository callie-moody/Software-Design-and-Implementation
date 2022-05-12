# CS50 Lab 3
## CS50 Summer 2021
## Callie Moody

### Set

A `set` is an unordered collection of _items_.
The `set` starts empty, grows as the caller adds one _item_ at a time.

### Usage

The *set* module, defined in `set.h` and implemented in `set.c`, implements a set of String keys pointing to `void*`, and exports the following functions:

```c
set_t *set_new(void);
bool set_insert(set_t *set, const char *key, void *item);
void *set_find(set_t *set, const char *key);
void set_print(set_t *set, FILE *fp, 
               void (*itemprint)(FILE *fp, const char *key, void *item) );
set_iterate(set_t *set, void *arg,
                 void (*itemfunc)(void *arg, const char *key, void *item) );
void set_delete(set_t *set, void (*itemdelete)(void *item) );
```

### Implementation

We implement this set as a linked list.
The *set* itself is represented as a `struct set` containing a pointer to the head of the list; the head pointer is NULL when the set is empty.

Each node in the list is a `struct setnode`, a type defined internally to the module.
Each setnode includes a pointer to the `void *item`, a pointer to the `char *key`, and a pointer to the next setnode on the list.

To insert a new item in the set we create a new setnode to hold the `item`, and insert it at the end of the list.

### Assumptions

None other than given in the assignment

### Files

* `Makefile` - compilation procedure
* `set.h` - the interface
* `set.c` - the implementation
* `settest.c` - unit test driver
* `test.keys` - test data
* `TESTING.md` - testing results results

### Compilation

To compile, simply `make set.o`.

### Testing

The `settest.c` program reads lines from stdin and stuffs them into a set, then pulls them back out.
It tests a few error and edge cases.
This test is somewhat minimal.
