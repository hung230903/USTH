#include <stdio.h>
#include <stdlib.h>

typedef struct Car {
    char id;                    
    int capacity;               
    int passengers;             
    struct Car *next;           
} Car;

Car* initializeCars(char id, int capacity, int passengers) {
    Car *new_car = (Car *)malloc(sizeof(Car));
    new_car->id = id;
    new_car->capacity = capacity;
    new_car->passengers = passengers;
    new_car->next = NULL;

    return new_car;
}

void addCar(Car **head, char id, int capacity, int passengers) {
    Car *new_car = initializeCars(id, capacity, passengers);
    
    if(*head == NULL){
        *head = new_car;
    } 
    else{
        Car *tmp = *head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = new_car;
    }
}

void removeEmptyCars(Car **head) {
    Car *tmp = *head;
    Car *prev = NULL;

    while(tmp != NULL) {
        if (tmp->passengers == 0) {
            if(prev == NULL){
                *head = tmp->next;
                free(tmp);
                tmp = *head;
                } 
            else{
                prev->next = tmp->next;
                free(tmp);
                tmp = prev->next;
            }
        } 
        else{
            prev = tmp;
            tmp = tmp->next;
        }
    }
}

void displayTrain(Car *head) {
    Car *tmp = head;
    while(tmp != NULL){
        printf("Car ID: %c, Capacity: %d, Passengers: %d\n", tmp->id, tmp->capacity, tmp->passengers);
        tmp = tmp->next;
    }
}

int getTrainLength(Car *head) {
    int length = 0;
    Car *tmp = head;
    while(tmp != NULL){
        length++;
        tmp = tmp->next;
    }

    return length;
}

int main() {
    Car *train = NULL;

    addCar(&train, '1', 10, 5);  
    addCar(&train, '2', 20, 0);   
    addCar(&train, '3', 30, 15);  
    addCar(&train, '4', 40, 25);  
    addCar(&train, '5', 50, 0);  

    printf("---\n");
    printf("Train before removing empty cars:\n");
    displayTrain(train);

    printf("---");
    removeEmptyCars(&train);
    printf("\nTrain after removing empty cars:\n");
    displayTrain(train);

    printf("---");
    int length = getTrainLength(train);
    printf("\nTrain length: %d", length);
}




