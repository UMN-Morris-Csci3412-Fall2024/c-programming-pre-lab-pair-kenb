# Leak report

By Ken Broden

- The memory errors are happening because the memory allocated by the ['strip'] function is not being freed after use.
- Each call to ['strip'] allocates memory using ['calloc'], but this memory is not released, leading to memory leaks

## Solution
  
- **Free the Memory in Tests:** Make sure the memory allocated by ['strip'] is freed after each test.
  - Modify the tests in ['check_whitespace_test.cpp'] to free the returned strings
  - Modify is_clean function - is_clean calls the strip() function. De-allocate memory at the end of is_clean to make sure there is no memory leak
  - Empty string does not need to be freed

```sh
==1077870== 
==1077870== HEAP SUMMARY:
==1077870==     in use at exit: 144 bytes in 8 blocks
==1077870==   total heap usage: 308 allocs, 300 frees, 122,875 bytes allocated
==1077870== 
==1077870== 5 bytes in 1 blocks are definitely lost in loss record 1 of 8
==1077870==    at 0x484BF70: calloc (vg_replace_malloc.c:1595)
==1077870==    by 0x4024D8: strip(char const*) (check_whitespace.c:36)
==1077870==    by 0x40268E: strip_NoWhitespace_Test::TestBody() (check_whitespace_test.cpp:10)
==1077870==    by 0x48B8E0B: ??? (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x4899825: testing::Test::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48999EF: testing::TestInfo::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x4899AF8: testing::TestSuite::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48A8FC4: testing::internal::UnitTestImpl::RunAllTests() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48A67C7: testing::UnitTest::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x403FAD: RUN_ALL_TESTS() (gtest.h:2490)
==1077870==    by 0x40313D: main (check_whitespace_test.cpp:47)
==1077870== 
==1077870== 5 bytes in 1 blocks are definitely lost in loss record 2 of 8
==1077870==    at 0x484BF70: calloc (vg_replace_malloc.c:1595)
==1077870==    by 0x4024D8: strip(char const*) (check_whitespace.c:36)
==1077870==    by 0x40279A: strip_WhitespaceOnFront_Test::TestBody() (check_whitespace_test.cpp:14)
==1077870==    by 0x48B8E0B: ??? (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x4899825: testing::Test::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48999EF: testing::TestInfo::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x4899AF8: testing::TestSuite::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48A8FC4: testing::internal::UnitTestImpl::RunAllTests() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48A67C7: testing::UnitTest::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x403FAD: RUN_ALL_TESTS() (gtest.h:2490)
==1077870==    by 0x40313D: main (check_whitespace_test.cpp:47)
==1077870== 
==1077870== 5 bytes in 1 blocks are definitely lost in loss record 3 of 8
==1077870==    at 0x484BF70: calloc (vg_replace_malloc.c:1595)
==1077870==    by 0x4024D8: strip(char const*) (check_whitespace.c:36)
==1077870==    by 0x4028A6: strip_WhitespaceOnBack_Test::TestBody() (check_whitespace_test.cpp:18)
==1077870==    by 0x48B8E0B: ??? (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x4899825: testing::Test::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48999EF: testing::TestInfo::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x4899AF8: testing::TestSuite::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48A8FC4: testing::internal::UnitTestImpl::RunAllTests() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48A67C7: testing::UnitTest::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x403FAD: RUN_ALL_TESTS() (gtest.h:2490)
==1077870==    by 0x40313D: main (check_whitespace_test.cpp:47)
==1077870== 
==1077870== 5 bytes in 1 blocks are definitely lost in loss record 4 of 8
==1077870==    at 0x484BF70: calloc (vg_replace_malloc.c:1595)
==1077870==    by 0x4024D8: strip(char const*) (check_whitespace.c:36)
==1077870==    by 0x4029B2: strip_WhitespaceOnBothEnds_Test::TestBody() (check_whitespace_test.cpp:22)
==1077870==    by 0x48B8E0B: ??? (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x4899825: testing::Test::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48999EF: testing::TestInfo::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x4899AF8: testing::TestSuite::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48A8FC4: testing::internal::UnitTestImpl::RunAllTests() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48A67C7: testing::UnitTest::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x403FAD: RUN_ALL_TESTS() (gtest.h:2490)
==1077870==    by 0x40313D: main (check_whitespace_test.cpp:47)
==1077870== 
==1077870== 31 bytes in 1 blocks are definitely lost in loss record 5 of 8
==1077870==    at 0x484BF70: calloc (vg_replace_malloc.c:1595)
==1077870==    by 0x4024D8: strip(char const*) (check_whitespace.c:36)
==1077870==    by 0x402544: is_clean(char const*) (check_whitespace.c:56)
==1077870==    by 0x402C04: is_clean_NoWhitespace_Test::TestBody() (check_whitespace_test.cpp:30)
==1077870==    by 0x48B8E0B: ??? (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x4899825: testing::Test::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48999EF: testing::TestInfo::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x4899AF8: testing::TestSuite::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48A8FC4: testing::internal::UnitTestImpl::RunAllTests() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48A67C7: testing::UnitTest::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x403FAD: RUN_ALL_TESTS() (gtest.h:2490)
==1077870==    by 0x40313D: main (check_whitespace_test.cpp:47)
==1077870== 
==1077870== 31 bytes in 1 blocks are definitely lost in loss record 6 of 8
==1077870==    at 0x484BF70: calloc (vg_replace_malloc.c:1595)
==1077870==    by 0x4024D8: strip(char const*) (check_whitespace.c:36)
==1077870==    by 0x402544: is_clean(char const*) (check_whitespace.c:56)
==1077870==    by 0x402D4A: is_clean_WhitespaceOnFront_Test::TestBody() (check_whitespace_test.cpp:34)
==1077870==    by 0x48B8E0B: ??? (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x4899825: testing::Test::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48999EF: testing::TestInfo::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x4899AF8: testing::TestSuite::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48A8FC4: testing::internal::UnitTestImpl::RunAllTests() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48A67C7: testing::UnitTest::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x403FAD: RUN_ALL_TESTS() (gtest.h:2490)
==1077870==    by 0x40313D: main (check_whitespace_test.cpp:47)
==1077870== 
==1077870== 31 bytes in 1 blocks are definitely lost in loss record 7 of 8
==1077870==    at 0x484BF70: calloc (vg_replace_malloc.c:1595)
==1077870==    by 0x4024D8: strip(char const*) (check_whitespace.c:36)
==1077870==    by 0x402544: is_clean(char const*) (check_whitespace.c:56)
==1077870==    by 0x402E96: is_clean_WhitespaceOnBack_Test::TestBody() (check_whitespace_test.cpp:38)
==1077870==    by 0x48B8E0B: ??? (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x4899825: testing::Test::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48999EF: testing::TestInfo::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x4899AF8: testing::TestSuite::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48A8FC4: testing::internal::UnitTestImpl::RunAllTests() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48A67C7: testing::UnitTest::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x403FAD: RUN_ALL_TESTS() (gtest.h:2490)
==1077870==    by 0x40313D: main (check_whitespace_test.cpp:47)
==1077870== 
==1077870== 31 bytes in 1 blocks are definitely lost in loss record 8 of 8
==1077870==    at 0x484BF70: calloc (vg_replace_malloc.c:1595)
==1077870==    by 0x4024D8: strip(char const*) (check_whitespace.c:36)
==1077870==    by 0x402544: is_clean(char const*) (check_whitespace.c:56)
==1077870==    by 0x402FE2: is_clean_WhitespaceOnBothEnds_Test::TestBody() (check_whitespace_test.cpp:42)
==1077870==    by 0x48B8E0B: ??? (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x4899825: testing::Test::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48999EF: testing::TestInfo::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x4899AF8: testing::TestSuite::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48A8FC4: testing::internal::UnitTestImpl::RunAllTests() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x48A67C7: testing::UnitTest::Run() (in /usr/lib64/libgtest.so.1.11.0)
==1077870==    by 0x403FAD: RUN_ALL_TESTS() (gtest.h:2490)
==1077870==    by 0x40313D: main (check_whitespace_test.cpp:47)
==1077870== 
==1077870== LEAK SUMMARY:
==1077870==    definitely lost: 144 bytes in 8 blocks
==1077870==    indirectly lost: 0 bytes in 0 blocks
==1077870==      possibly lost: 0 bytes in 0 blocks
==1077870==    still reachable: 0 bytes in 0 blocks
==1077870==         suppressed: 0 bytes in 0 blocks
==1077870== 
==1077870== For lists of detected and suppressed errors, rerun with: -s
==1077870== ERROR SUMMARY: 8 errors from 8 contexts (suppressed: 0 from 0)
```
