# CS50 Lab 3
## CS50 Summer 2021
## Callie Moody

### Counter

A `corunte` is an unordered collection of _items_.
The `counter` starts empty, grows as the caller adds one _item_ at a time.

### Usage

The *set* module, defined in `counters.h` and implemented in `counters.c`, implements a set of int keys with int counts, and exports the following functions:

```c
counters_t *counters_new(void);

int counters_add(counters_t *ctrs, const int key);

int counters_get(counters_t *ctrs, const int key);

bool counters_set(counters_t *ctrs, const int key, const int count);

void counters_print(counters_t *ctrs, FILE *fp);

void counters_iterate(counters_t *ctrs, void *arg, 
                      void (*itemfunc)(void *arg, 
                                       const int key, const int count));


void counters_delete(counters_t *ctrs);
```

### Implementation

We implement this counter as a linked list.
The *counter* itself is represented as a `struct counters` containing a pointer to the head of the list; the head pointer is NULL when the set is empty.

Each node in the list is a `struct countersnode`, a type defined internally to the module.
Each setnode includes a pointer to the key, count, and a pointer to the next counter on the list.

To insert a new item in the set we create a new countersnode to hold the `key`, and insert it at the head of the list. Double insertions are allowed, and will increment the count associated with the key.

### Assumptions

None other than given in the assignment

### Files

* `Makefile` - compilation procedure
* `counters.h` - the interface
* `counters.c` - the implementation
* `countertest.c` - unit test driver
* `test.keys` - test data
* `TESTING.md` - testing results results

### Compilation

To compile, simply `make counters.o`.

### Testing

The `countertest.c` program reads lines from stdin and stuffs them into a counter, then pulls them back out.
It tests a few error and edge cases.
This test is somewhat minimal.
