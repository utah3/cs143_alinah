#include <stdio.h>
#include <stdlib.h>


/*tests*/
void test_all_ofty();
void test_exists_ofty();
void test_first_ofty();
void test_number_ofty();
void test_progress();
void test_running_ofty();
void test_rotate_right();
unsigned int reslen;

int main() {
    test_all_ofty();
    test_exists_ofty();
    test_first_ofty();
    test_number_ofty();
    test_progress();
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
    printf("Test 4: %d (expected 0)\n", all_ofty(test4, 0));
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
    printf("Test 2: %d (expected 2)\n", first_ofty(test2, 3));
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

void test_progress() {
    unsigned int test[] = {140, 141, 142, 143, 144};
    unsigned int expected[] = {0, 142, 143, 144, 0};

    progress(test, 5);
    printf("test_progress:\n");
    for (int i = 0; i < 5; i++) {
        printf("Expected: %d, Actual: %d\n", expected[i], test[i]);
    }
}

void test_running_ofty() {
    unsigned int test1[] = {1, 2, 3, 4};
    unsigned int test2[] = {2, 4, 6};
    unsigned int test3[] = {};
    unsigned int *test4 = NULL;

    unsigned int *result1 = running_ofty(test1, 4);
    unsigned int *result2 = running_ofty(test2, 3);
    unsigned int *result3 = running_ofty(test3, 0);
    unsigned int *result4 = running_ofty(test4, 3);

    printf("test_running_ofty:\n");
    /* Check results for test1*/
    printf("Test 1: ");
    if (result1) {
        for (int i = 0; i < 2; i++) { 
            printf("%d ", result1[i]);
        }
        printf("(expected 2)\n");
        free(result1);
    }

    /* Check results for test2*/
    printf("Test 2: ");
    if (result2) {
        for (int i = 0; i < 3; i++) { 
            printf("%d ", result2[i]);
        }
        printf("(expected 3)\n");
        free(result2);
    }

    /* Check results for null*//
    printf("Test 3: %s (expected NULL)\n", result3 == NULL ? "NULL" : "Not NULL");
    printf("Test 4: %s (expected NULL)\n", result4 == NULL ? "NULL" : "Not NULL");
}

void test_rotate_right() {
    /* Test cases*/
    int test1[] = {1, 2, 3, 4, 5};
    rotate_right(test1, 5);
    printf("Test 1: {5, 1, 2, 3, 4} - Result: {");
    for (int i = 0; i < 5; i++) printf("%d%s", test1[i], (i < 4) ? ", " : "}\n");

    int test2[] = {10, 20};
    rotate_right(test2, 2);
    printf("Test 2: {20, 10} - Result: {");
    for (int i = 0; i < 2; i++) printf("%d%s", test2[i], (i < 1) ? ", " : "}\n");

    int test3[] = {7};
    rotate_right(test3, 1);
    printf("Test 3: {7} - Result: {");
    printf("%d}\n", test3[0]);

    printf("Test 4: (empty array, no output expected)\n");
    rotate_right(NULL, 0); /* Should handle without crash*/
}

void test_trim_adj_dupes() {
    unsigned int reslen;

    int arr1[] = {1, 1, 2, 2, 3};
    int* result1 = trim_adj_dupes(arr1, 5, &reslen);
    printf("Test 1: {");
    for (unsigned int i = 0; i < reslen; i++) printf("%d%s", result1[i], (i < reslen - 1) ? ", " : "");
    printf("} (Expected: {1, 2, 3})\n");
    free(result1);

    int arr2[] = {5, 5, 5};
    int* result2 = trim_adj_dupes(arr2, 3, &reslen);
    printf("Test 2: {");
    printf("%d} (Expected: {5})\n", result2[0]);
    free(result2);

    int* result3 = trim_adj_dupes(NULL, 0, &reslen);
    printf("Test 3: %s (Expected: NULL)\n", result3 == NULL ? "NULL" : "Not NULL");
}
