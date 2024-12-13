#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: doubly linked list
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
listint_t *ptr_up, *ptr_desc, *temp;
/*si la liste est vide ou contient un seul element, il n'y a rien a trier*/
if (list == NULL || *list == NULL || (*list)->next == NULL)
  return;
/*ptr_up est le pointeur utilisé pour parcourir la liste en partant du 2eme element*/  
ptr_up = (*list)->next;
  
while (ptr_up != NULL)
  {
  ptr_desc = ptr_up;
  ptr_up = ptr_up->next;
/*tant que l'element actuel est plus petit que l'element precedent on l'echange avec le precedent*/
    while (ptr_desc->prev != NULL && ptr_desc->n < ptr_desc->prev->n)
      {
      temp = ptr_desc->prev; /*temp garde une ref du noeud prev*/
      if (temp->prev == NULL) /*si temp est le 1er noeud*/
        *list = ptr_desc; /*mettre a jour la tete de liste*/
/*reajustement des connexions entre les noeuds*/        
      temp->next = ptr_desc->next;
      if (ptr_desc->next)
        ptr_desc->next->prev = temp;
      ptr_desc->prev = temp->prev;
      if (temp->prev)
        temp->prev->next = ptr_desc;
      ptr_desc->next = temp;
      temp->prev = ptr_desc;
print_list(*list); /*impression de la liste a chaque modification*/
      }
    }
}
