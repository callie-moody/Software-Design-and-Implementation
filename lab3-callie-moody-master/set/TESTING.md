# CS50 Lab 3
## CS50 Summer 2021

### Functionality test

Various functionality tests are conducted in settest.c: 

* TEST 1: creating an empty set
* TEST 2: inserting nodes into a valid set (and duplicates)
* TEST 3: inserting null items into a valid set
* TEST 4: inserting null items into a null set
* TEST 5: finding in a valid set
* TEST 6: printing nodes in a valid set
* TEST 7: iterating to print set
* TEST 8: deleting a valid set


#### Functionality test output
```bash
$ make test
./settest < test.keys
testing set_insert...
testing extranneous set_insert...
finding....
found
The set:
{Key key1   Item item1,
Key key2   Item item2,
Key key3   Item item3,
Key findme   Item found}

Iterated Print:
Key key1   Item item1
Key key2   Item item2
Key key3   Item item3
Key findme   Item found

delete the bag...
```

The above output excludes the compilation output with `gcc`.


### Memory test
```bash
$ make clean; make valgrind
==37729== 
==37729== HEAP SUMMARY:
==37729==     in use at exit: 0 bytes in 0 blocks
==37729==   total heap usage: 136 allocs, 136 frees, 15,707 bytes allocated
==37729== 
==37729== All heap blocks were freed -- no leaks are possible
==37729== 
==37729== For lists of detected and suppressed errors, rerun with: -s
==37729== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

The above output excludes the compilation output and the test program's normal output.



