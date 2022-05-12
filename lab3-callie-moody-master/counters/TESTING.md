# CS50 Lab 3
## CS50 Summer 2021

### Functionality test

Various functionality tests are conducted in countertest.c: 

* TEST 1: creating an empty sounter
* TEST 2: inserting nodes into a valid counter
* TEST 3: setting a counter for a given key
* TEST 4: inserting out of bounds item into a valid counter
* TEST 5: iterate through and print counter
* TEST 6: printing nodes in a valid counter
* TEST 7: deleting a valid counter


#### Functionality test output
```bash
$ make test
./countertest < test.keys
testing add...enter keys
testing add...entering null key
set the 12 counter to 17...
get the 12 counter(should be 17)...17 
iterate print the counter...
1=1
2=3
23=1
3=4
4=2
45=1
6=1
12=17
print the counter...
{1=1,2=3,23=1,3=4,4=2,45=1,6=1,12=17}
delete the counter...
```

The above output excludes the compilation output with `gcc`.


### Memory test
```bash
$ make valgrind

==27549== HEAP SUMMARY:
==27549==     in use at exit: 0 bytes in 0 blocks
==27549==   total heap usage: 16 allocs, 16 frees, 9,420 bytes allocated
==27549== 
==27549== All heap blocks were freed -- no leaks are possible
==27549== 
==27549== For counts of detected and suppressed errors, rerun with: -v
==27549== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

The above output excludes the compilation output and the test program's normal output.



