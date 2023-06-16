#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  char letter;
  struct node *next;
} node;
// Returns number of nodes in the linkedList.
int length(node *head) {
  int length = 0;
  node *temp;
  temp = head;
  while (true) {
    length++;
    if (temp->next == NULL) {
      break;
    } else {
      temp = temp->next;
    }
  }
  return length;
}

// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char *toCString(node *head) {
  int strLen, i;
  node *temp;
  temp = head;
  strLen = length(head);
  char *str = (char *)malloc(strLen * sizeof(char));
  for (i = 0; i < strLen; i++) {
    *(str + i) = temp->letter;
    if (temp->next == NULL) {
      break;
    }
    temp = temp->next;
  }
  *(str + strLen) = '\0';
  return str;
}
// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node **pHead, char c) {
  node* temp;
  node* t;
  temp = (node*)malloc(sizeof(char));
  temp->letter = c;
  temp->next = NULL;
  if(*pHead == NULL){
    *pHead = temp;
  }
  else{
    t = *pHead;
    while(t->next != NULL){
      t = t->next;
    }
    t->next = temp;
  }
}
// deletes all nodes in the linkedList.
void deleteList(node **pHead) {
  int strLen, i;
  strLen = length(*pHead);
  node* temp;
  node* t;
  temp = *pHead;
  t = temp->next;
  while(t != NULL){
    free(temp);
    temp = t;
    t = t->next;
  }
  *pHead = NULL;
}
int main(void) {
  int i, strLen, numInputs;
  node *head = NULL;
  char *str;
  char c;
  FILE *inFile = fopen("input.txt", "r");
  fscanf(inFile, " %d\n", &numInputs);
  while (numInputs-- > 0) {
    fscanf(inFile, " %d\n", &strLen);
    for (i = 0; i < strLen; i++) {
      fscanf(inFile, " %c", &c);
      insertChar(&head, c);
    }
    str = toCString(head);
    printf("String is : %s\n", str);
    free(str);
    deleteList(&head);
    if (head != NULL) {
      printf("deleteList is not correct!");
      break;
    }
  }
  fclose(inFile);
}
