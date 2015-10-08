#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *node_init(val) {
    struct ListNode *node = malloc(sizeof(struct ListNode *));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode *list_from_array(int *nums, int n) {
    int i = n - 1;
    struct ListNode *head = NULL;
    while (i >= 0) {
        if (head == NULL) {
            head = node_init(nums[i]);
        } else {
            struct ListNode *node = node_init(nums[i]);
            node->next = head;
            head = node;
        }
        i --;
    }
    return head;
}

void free_list(struct ListNode *list) {
    struct ListNode *head = list;
    struct ListNode *temp = NULL;
    while (head != NULL) {
        temp = head->next;
        free(head);
        head = temp;
    }
}

int check_list(struct ListNode *list) {
    if (list == NULL) {
        return 0;
    }
    struct ListNode *head = list;
    while (head->next != NULL) {
        if (head->next->val < head->val) {
            return 0;
        }
        head = head->next;
    }
    return 1;
}

void print_list(struct ListNode *list) {
    printf("List: [ ");
    struct ListNode *head = list;
    int k = 0;
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
        k += 1;
        if (k > 20) {
            break;
        }
    }
    printf("]\n");
}

int list_length(struct ListNode *list) {
    struct ListNode *head = list;
    int k = 0;
    while (head != NULL) {
        head = head->next;
        k += 1;
        if (k > 20) {
            break;
        }
    }
    return k;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    struct ListNode *head = NULL;
    struct ListNode *temp = NULL;
    struct ListNode *L = l1;
    struct ListNode *R = l2;

    while (L != NULL && R != NULL) {
        if (head == NULL) {
            if (L->val < R->val) {
                head = L;
                temp = L;
                L = L->next;
            } else {
                head = R;
                temp = R;
                R = R->next;
            }
        } else {
            if (L->val < R->val) {
                temp->next = L;
                temp = L;
                L = L->next;
            } else {
                temp->next = R;
                temp = R;
                R = R->next;
            }
        }
    }
    struct ListNode *tail = (R == NULL) ? L : R;
    temp->next = tail;
    temp = tail;
    return head;
}


void test_merge_sort_case1(void) {
    struct ListNode *l1 = list_from_array((int []){1, 2, 5, 6, 10}, 5);
    struct ListNode *l2 = list_from_array((int []){0, 3, 4, 7, 9}, 5);
    struct ListNode *l3 = mergeTwoLists(l1, l2);
    assert(check_list(l3) == 1);
    assert(list_length(l3) == 10);
    free_list(l3);
}

void test_merge_sort_case2(void) {
    struct ListNode *l1 = list_from_array((int []){0}, 1);
    struct ListNode *l2 = list_from_array((int []){1}, 1);

    struct ListNode *l3 = mergeTwoLists(l1, l2);
    assert(check_list(l3) == 1);
    assert(list_length(l3) == 2);
    free_list(l3);
}

void test_merge_sort_case3(void) {
    struct ListNode *l1 = list_from_array((int []){1}, 1);
    struct ListNode *l2 = list_from_array((int []){1}, 1);

    struct ListNode *l3 = mergeTwoLists(l1, l2);
    assert(check_list(l3) == 1);
    assert(list_length(l3) == 2);
    free_list(l3);
}

void test_merge_sort_case4(void) {
    struct ListNode *l1 = list_from_array((int []){5}, 1);
    struct ListNode *l2 = list_from_array((int []){1, 2, 4}, 3);

    struct ListNode *l3 = mergeTwoLists(l1, l2);
    assert(check_list(l3) == 1);
    assert(list_length(l3) == 4);
    free_list(l3);
}

int main(int argc, char const *argv[])
{
    test_merge_sort_case1();
    test_merge_sort_case2();
    test_merge_sort_case3();
    test_merge_sort_case4();
    return 0;
}
