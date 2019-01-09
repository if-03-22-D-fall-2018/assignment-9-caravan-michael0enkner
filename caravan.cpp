/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdlib.h>
#include "caravan.h"
#include "general.h"

struct NodeImplementation{
  PackAnimal animal;
  Node next;
};

struct CaravanImplementation{
  int length;
  Node head;
};

Caravan new_caravan()
{
  Caravan caravan = (Caravan) malloc(sizeof(struct CaravanImplementation));
  caravan->length = 0;
  caravan->head = 0;
  return caravan;
}

int get_length(Caravan caravan)
{
  return caravan->length;
}

void delete_caravan(Caravan caravan)
{
  Node current = caravan->head;
  while(current != 0)
  {
    Node should_delete = current;
    current = current->next;
    sfree(should_delete);
  }
  sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if(animal != 0)
    {
        if(get_caravan(animal) != 0 && get_caravan(animal) != caravan)
        {
            remove_pack_animal(get_caravan(animal), animal);
        }
        Node current = caravan->head;
        Node n_Animal = (Node)malloc(sizeof(current));
        n_Animal->animal = animal;
        n_Animal->next = 0;
        if(caravan->head == 0)
        {
            caravan->head = n_Animal;
        }
        else
        {
            while(current->next != 0)
            {
                if(current->animal == animal)
                {
                   return;
                }
                current = current->next;
            }
            if(current->animal == animal)
            {
              return;
            }
            current->next = n_Animal;
        }
        add_to_caravan(animal, caravan);
        caravan->length++;
      }
 }

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  if(animal!=0)
  {
    Node current = caravan->head;
    Node prev;
    if(current != 0 && current->animal == animal)
    {
        caravan->head = current->next;
        remove_from_caravan(animal, caravan);
        sfree(current);
        caravan->length--;
    }
    else
    {
      while(current != 0 && current->animal != animal)
      {
          prev = current;
          current = current->next;
      }
      if(current!=0)
      {
        prev->next = current->next;
        remove_from_caravan(animal, caravan);
        sfree(current);
        caravan->length--;
      }
    }
  }
}

int get_caravan_load(Caravan caravan)
{
  Node current = caravan->head;
  int load = 0;
  while(current!=0)
  {
      load += get_load(current->animal);
      current = current->next;
  }
  return load;
}

void unload(Caravan caravan)
{
  Node current = caravan->head;
 while(current != 0)
 {
     unload(current->animal);
     current = current->next;
  }
}

int get_caravan_speed(Caravan caravan)
{
  Node current = caravan->head;
  int speed = 50;
  while(current!=0)
  {
    if(get_actual_speed(current->animal)<speed){
          speed = get_actual_speed(current->animal);
      }
      current = current->next;
  }
return speed;
}

void optimize_load(Caravan caravan)
{

}
