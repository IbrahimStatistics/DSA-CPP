#include <stdio.h>
#include <string.h>

#define LANES    10
#define CAPACITY 5

typedef struct {
    int  carID;
    char licensePlate[10];
} Car;

typedef struct {
    Car  slots[CAPACITY];
    int  front;
    int  rear;
    int  size;
} Lane;

Lane garage[LANES];

void initGarage() {
    int i;
    for (i = 0; i < LANES; i++) {
        garage[i].front = 0;
        garage[i].rear  = 0;
        garage[i].size  = 0;
    }
}

void parkCar(int carID, char *plate) {
    int i, minLoad, selectedLane;
    minLoad      = CAPACITY + 1;
    selectedLane = -1;

    for (i = 0; i < LANES; i++) {
        if (garage[i].size < CAPACITY && garage[i].size < minLoad) {
            minLoad      = garage[i].size;
            selectedLane = i;
        }
    }

    if (selectedLane == -1) {
        printf("Full. Car %d not parked.\n", carID);
        return;
    }

    garage[selectedLane].slots[garage[selectedLane].rear].carID = carID;
    strncpy(garage[selectedLane].slots[garage[selectedLane].rear].licensePlate,
            plate, 9);
    garage[selectedLane].slots[garage[selectedLane].rear].licensePlate[9] = '\0';
    garage[selectedLane].rear  = (garage[selectedLane].rear + 1) % CAPACITY;
    garage[selectedLane].size += 1;

    printf("P%d->L%d\n", carID, selectedLane);
}

void retrieveCar(int laneNumber) {
    Car retrieved;
    if (laneNumber < 0 || laneNumber >= LANES) {
        printf("Invalid lane %d\n", laneNumber);
        return;
    }
    if (garage[laneNumber].size == 0) {
        printf("Lane %d empty\n", laneNumber);
        return;
    }

    retrieved = garage[laneNumber].slots[garage[laneNumber].front];
    garage[laneNumber].front  = (garage[laneNumber].front + 1) % CAPACITY;
    garage[laneNumber].size  -= 1;

    printf("R%d L%d\n", retrieved.carID, laneNumber);
}

void displayGarage() {
    int i, j, idx;
    printf("\n-- GARAGE --\n");
    for (i = 0; i < LANES; i++) {
        printf("L%d(%d):", i, garage[i].size);
        idx = garage[i].front;
        for (j = 0; j < garage[i].size; j++) {
            printf(" %d", garage[i].slots[idx].carID);
            idx = (idx + 1) % CAPACITY;
        }
        printf("\n");
    }
    printf("-------------\n\n");
}

int main() {
    int choice, carID, lane;
    char plate[10];

    initGarage();

    while (1) {
        printf("\n1.Park  2.Retrieve  3.Display  4.Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Car ID: ");
                scanf("%d", &carID);
                printf("Plate: ");
                scanf("%s", plate);
                parkCar(carID, plate);
                break;

            case 2:
                printf("Lane: ");
                scanf("%d", &lane);
                retrieveCar(lane);
                break;

            case 3:
                displayGarage();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}