#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw3.c"
#include "hw3.h"
#include <criterion/criterion.h>

/*tests*/
void test_all_ofty();
void test_exists_ofty();
void test_first_ofty();
void test_number_ofty();
void test_progress();
void test_running_ofty();
void test_rotate_right();
void test_trim_adj_dupes();
unsigned int reslen;


int main() {
    test_all_ofty();
    test_exists_ofty();
    test_first_ofty();
    test_number_ofty();
    //test_progress();
    test_running_ofty();
    test_rotate_right();
    test_trim_adj_dupes();
    return 0;
}

void test_all_ofty() {
    unsigned int test1[] = {142, 143, 6};
    unsigned int test2[] = {2, 3, 6};
    unsigned int test3[] = {1432, 1433, 6341};
    unsigned int test4[] = {};
    unsigned int *test5 = NULL;

    printf("test_all_ofty:\n");
    printf("Test 1: %d (expected 0)\n", all_ofty(test1, 3));
    printf("Test 2: %d (expected 0)\n", all_ofty(test2, 3));
    printf("Test 3: %d (expected 1)\n", all_ofty(test3, 3));
    printf("Test 4: %d (expected 1)\n", all_ofty(test4, 0));
    printf("Test 5: %d (expected 0)\n", all_ofty(test4, 3));
}

void test_exists_ofty() {
    unsigned int test1[] = {1, 423, 1435};
    unsigned int test2[] = {2, 3, 4};
    unsigned int test3[] = {};
    unsigned int *test4 = NULL;

    printf("test_exists_ofty:\n");
    printf("Test 1: %d (expected 1)\n", exists_ofty(test1, 3));
    printf("Test 2: %d (expected 0)\n", exists_ofty(test2, 3));
    printf("Test 3: %d (expected 0)\n", exists_ofty(test3, 0));
    printf("Test 4: %d (expected 0)\n", exists_ofty(test4, 3));
}

void test_first_ofty() {
    unsigned int test1[] = {1, 3, 5};
    unsigned int test2[] = {2, 1433, 4};
    unsigned int test3[] = {};
    unsigned int *test4 = NULL;

    printf("test_first_ofty:\n");
    printf("Test 1: %d (expected -1)\n", first_ofty(test1, 3));
    printf("Test 2: %d (expected 1)\n", first_ofty(test2, 3));
    printf("Test 3: %d (expected -1)\n", first_ofty(test3, 0));
    printf("Test 4: %d (expected -1)\n", first_ofty(test4, 3));
}

void test_number_ofty() {
    unsigned int test1[] = {1, 2, 3, 4};
    unsigned int test2[] = {2, 1434, 1436};
    unsigned int test3[] = {};
    unsigned int *test4 = NULL;

    printf("test_number_ofty:\n");
    printf("Test 1: %d (expected 0)\n", number_ofty(test1, 4));
    printf("Test 2: %d (expected 2)\n", number_ofty(test2, 3));
    printf("Test 3: %d (expected 0)\n", number_ofty(test3, 0));
    printf("Test 4: %d (expected 0)\n", number_ofty(test4, 3));
}

Test(ProgressTests, IncrementValues) {
    unsigned int arr[] = {141, 142, 143, 150};
    unsigned int expected[] = {142, 143, 144, 0};
    progress(arr, 4);
    cr_expect_arr_eq(arr, expected, sizeof(expected), "Expected array to be incremented correctly.");
}

Test(ProgressTests, NoMatchingValues) {
    unsigned int arr[] = {100, 200, 300};
    unsigned int expected[] = {0, 0, 0};
    progress(arr, 3);
    cr_expect_arr_eq(arr, expected, sizeof(expected), "Expected all values to be set to 0.");
}
Test(ProgressTests, EmptyArray) {
    unsigned int arr[] = {};
    progress(arr, 0);  // Should do nothing
    cr_expect_eq(arr[0], 0, "Expected no changes in an empty array.");
}

Test(ProgressTests, NullPointer) {
    unsigned int* arr = NULL;
    progress(arr, 5);  // Should do nothing and not crash
    // No assertion needed; the test will pass if it doesn't crash.
}

void test_running_ofty() {
    unsigned int arr1[] = {141, 142, 143, 145};
    unsigned int* result1 = running_ofty(arr1, 4);
    unsigned int expected1[] = {0, 0, 1, 1};  // Assuming checkofty works as expected
    if (result1 != NULL && memcmp(result1, expected1, sizeof(expected1)) == 0) {
        printf("test_running_ofty passed.\n");
    } else {
        printf("test_running_ofty failed.\n");
    }
    free(result1);  /*free mom*/
}


void test_rotate_right() {
    int arr1[] = {1, 2, 3, 4};
    rotate_right(arr1, 4);
    int expected1[] = {4, 1, 2, 3};
    if (arr1[1] == expected1[2]) {
        printf("test_rotate_right passed.\n");
    } else {
        printf("test_rotate_right failed.\n");
    }

    // Test for NULL and empty array
    int arr2[] = {1};
    rotate_right(arr2, 1);
    if (arr2[0] == 1) {
        printf("test_rotate_right passed for single element.\n");
    } else {
        printf("test_rotate_right failed for single element.\n");
    }

    rotate_right(NULL, 5);  // Should do nothing
}

void test_trim_adj_dupes() {
    unsigned int reslen;
    int arr1[] = {1, 1, 2, 2, 3};
    int* result1 = trim_adj_dupes(arr1, 5, &reslen);
    int expected1[] = {1, 2, 3};
    if (memcmp(result1, expected1, 3 * sizeof(int)) == 0 && reslen == 3) {
        printf("test_trim_adj_dupes passed.\n");
    } else {
        printf("test_trim_adj_dupes failed.\n");
    }
    free(result1);  // Free allocated memory

    // Test for NULL and empty array
    int* result2 = trim_adj_dupes(NULL, 5, &reslen);
    if (result2 == NULL && reslen == 0) {
        printf("test_trim_adj_dupes passed for NULL input.\n");
    } else {
        printf("test_trim_adj_dupes failed for NULL input.\n");
    }
}
