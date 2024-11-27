#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int currentId = 0;
struct Element
{
  int id;
  char* vorname;
  char* name;
  int age;
  struct Element* next;
};

struct List
{
  struct Element* head;
};

struct List createList()
{
  struct List list;
  list.head = (struct Element*)malloc(sizeof(struct Element));
  list.head->id = currentId++;
  list.head->vorname = "Header";
  list.head->name = "Header";
  list.head->age = 0;
  list.head->next = NULL;
  return list;
}

struct Element* getLastElement(struct List* list)
{
  struct Element* last;
  last = list->head;
  while (last->next != NULL)
  {
    last = last->next;
  }
  return last;
}


void createNewElement(struct List* list, char* vorname, char* name, int age)
{
  struct Element* el = (struct Element*)malloc(sizeof(struct Element));
  el->id = currentId++;
  el->vorname = vorname;
  el->name = name;
  el->age = age;
  el->next = NULL;

  struct Element* last = getLastElement(list);
  last->next = el;


  //printf("Der Name Existiert bereits in der Liste.\n");
}

void createNewElementAtBeginning(struct List* list, char* vorname, char* name, int age)
{
  struct Element* el = (struct Element*)malloc(sizeof(struct Element));
  el->id = currentId++;
  el->vorname = vorname;
  el->name = name;
  el->age = age;
  el->next = list->head->next;

  list->head->next = el;
}


void displayElement(struct List* list, int index)
{
  struct Element* element = list->head;
  for (int i = 0; i < index; i++)
  {
    element = element->next;
  }
  printf("|%i| ID: %i \n\tName: %s %s \n\tAlter: %i", index, element->id, element->vorname, element->name, element->age);
  //if (element != getLastElement(list))
  //{
  //  printf(" (->%s %s)\n", element->next->name, element->next->name);
  //}else
  //{
    printf("\n");
  //}
}

void printList(struct List* list)
{
  struct Element* current = list->head;
  int i = 0;
  while (current != NULL)
  {
    displayElement(list, i);
    current = current->next;
    i++;
  }
  printf("\n");
}

// void printDetailedList(struct List* list)
// {
//   for(int i=0; i<3;i++)
//   {
//     struct Element* current = list->head;
//     int j = 0;
//     while (current != NULL)
//     {
//       if(i == 0)
//       {
//         printf("%s ", current->name);
//       }
//       else if(i == 1)
//       {
//         printf("%i ", current->age);
//       }
//       current = current->next;
//       j++;
//     }
//     printf("\n");
//   }
// }

int findSmallestElement(struct List* list)
{
  struct Element* current = list->head->next;
  int value = current->age;
  while (current != NULL)
  {
    if (current->age < value)
    {
      value = current->age;
    }
    current = current->next;
  }

  return value;
}

void deleteElement(struct List* list, int id)
{
  struct Element* current = list->head;
  struct Element* previous = current;
  current = current->next;
  while (current != NULL)
  {
    if (current->id == id)
    {
      previous->next = current->next;
      printf("Element mit der ID %i gelöscht.\n", id);
    }
    previous = current;
    current = current->next;
  }
}

int isListEmpty(struct List* list)
{
  if (list->head->next == NULL) return 1;
  return 0;
}

void checkIfListIsEmpty(struct List* list)
{
  if (isListEmpty(list) == 1)
  {
    printf("Die Liste ist leer.\n");
  }else
  {
    printf("Die Liste ist nicht leer.\n");
  }
}

struct Element* findElementWithId(struct List* list, int id)
{
  struct Element* current = list->head;
  while (current != NULL)
  {
    if (current->id == id)
    {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

struct Element* getPrevious(struct List* list, int id)
{
  struct Element* current = list->head;
  struct Element* previous = current;
  while (current != NULL)
  {
    if (current->id == id)
    {
      return previous;
    }
    previous = current;
    current = current->next;
  }
  return NULL;
}

void swap(struct Element* a, struct Element* b)
{

}

void compareElements(struct List* list, int first, int second, int direction)
{
  if (first == second) return;

  struct Element* firstElem = findElementWithId(list, first);
  struct Element* secondElem = findElementWithId(list, second);

  if (!firstElem || !secondElem) return;

  struct Element* prevFirst = getPrevious(list, first);
  struct Element* prevSecond = getPrevious(list, second);

  if ((firstElem->age > secondElem->age && direction == 0) || (firstElem->age < secondElem->age && direction == 1))
  {
    if (prevFirst) prevFirst->next = secondElem;
    else list->head = secondElem;

    if (prevSecond) prevSecond->next = firstElem;

    struct Element* temp = firstElem->next;
    firstElem->next = secondElem->next;
    secondElem->next = temp;
  }
}


int countElements(struct List* list)
{
  struct Element* current = list->head;
  int count = 0;
  while (current != NULL)
  {
    count++;
    current = current->next;
  }
  return count;
}

int getIdAtPosition(struct List* list, int index)
{
  struct Element* current = list->head;
  for (int i = 0; i < index; i++)
  {
    current = current->next;
  }
  return current->id;
}

int getIndexById(struct List* list, int id)
{
  struct Element* current = list->head;
  int index = 0;
  while (current != NULL)
  {
    if (current->id == id)
    {
      return index;
    }
    current = current->next;
    index++;
  }
  return -1;
}

void bubbleSort(struct List* list, int direction)
{
  int n = countElements(list) - 1;
  for (int i = 0; i < n; i++)
  {
    struct Element* current = list->head->next;
    while (current && current->next)
    {
      compareElements(list, current->id, current->next->id, direction);
      current = current->next;
    }
  }
}

int findElementByName(struct List* list, char* name)
{
  int id = -1;

  struct Element* current = list->head;
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0)
    {
      id = current->id;
    }
    current = current->next;
  }
  return id;
}


int main(){
  struct List list = createList();

  printf("\n");
  checkIfListIsEmpty(&list);
  printf("\n");
  createNewElement(&list, "Nick", "Schwabellsand", 18);
  createNewElement(&list, "Sabinw", "NichtPicht", 18);
  printList(&list);
  createNewElement(&list, "Connor", "McGregor", 19);
  createNewElement(&list, "Jannik", "Abraham Lincoln", 18);
  createNewElementAtBeginning(&list, "Kacper", "Polski", 18);
  createNewElementAtBeginning(&list, "Gabriel", "lo", 17);
  createNewElement(&list, "Noel", "RATAJCZAK", 2);
  printList(&list);
  //printDetailedList(&list);
  printf("Kleinster Wert: %i\n", findSmallestElement(&list));
  deleteElement(&list, 2);
  deleteElement(&list, 1);
  deleteElement(&list, 5);
  deleteElement(&list, 6);
  printf("\n\n");
  printList(&list);
  checkIfListIsEmpty(&list);
  printf("\n");
  compareElements(&list, 3, 4, 0);
  printList(&list);

  printf("ID an der Postion %i: %i\n", 2, getIdAtPosition(&list, 2));
  printf("ID an der Postion %i: %i\n\n", 3, getIdAtPosition(&list, 3));

  createNewElement(&list, "Nicke", "Schwabelsand", 22);
  printf("Bubble sort aufsteigendes Alter:\n");
  bubbleSort(&list, 0);
  printList(&list);
  printf("Bubble sort absteigendes Alter:\n");
  bubbleSort(&list, 1);
  printList(&list);

  createNewElement(&list, "Nicke", "McGregor", 65);
  //printf("Alle Elemente mit dem Nachnamen '%s' werden ausgegeben:\n", "McGregor");
  displayElement(&list, getIndexById(&list, findElementByName(&list, "McGregor")));

  printf("\n\n");


  return 0;
}


