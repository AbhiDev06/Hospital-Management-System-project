#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HOSPITALS 100
#define MAX_PATIENTS 100

typedef struct {
    char name[100];
    char city[100];
    int availableBeds;
    int pricePerBed;
    float rating;
    char reviews[500];
} Hospital;

typedef struct {
    char name[100];
    int age;
    char disease[100];
    char hospital[100];
} Patient;

Hospital hospitals[MAX_HOSPITALS];
Patient patients[MAX_PATIENTS];
int numHospitals = 0;
int numPatients = 0;

void printHospitalData() {
    printf("\nHospital Data:\n");
    for (int i = 0; i < numHospitals; i++) {
        printf("Name: %s\n", hospitals[i].name);
        printf("City: %s\n", hospitals[i].city);
        printf("Available Beds: %d\n", hospitals[i].availableBeds);
        printf("Price per Bed: %d\n", hospitals[i].pricePerBed);
        printf("Rating: %.2f\n", hospitals[i].rating);
        printf("Reviews: %s\n\n", hospitals[i].reviews);
    }
}

void printPatientData() {
    printf("\nPatient Data:\n");
    for (int i = 0; i < numPatients; i++) {
        printf("Name: %s\n", patients[i].name);
        printf("Age: %d\n", patients[i].age);
        printf("Disease: %s\n", patients[i].disease);
        printf("Hospital: %s\n\n", patients[i].hospital);
    }
}

int compareByPrice(const void *a, const void *b) {
    return ((Hospital*)a)->pricePerBed - ((Hospital*)b)->pricePerBed;
}

int compareByAvailableBeds(const void *a, const void *b) {
    return ((Hospital*)b)->availableBeds - ((Hospital*)a)->availableBeds;
}

int compareByName(const void *a, const void *b) {
    return strcmp(((Hospital*)a)->name, ((Hospital*)b)->name);
}

int compareByRating(const void *a, const void *b) {
    return ((Hospital*)b)->rating - ((Hospital*)a)->rating;
}

void sortHospitals(int choice) {
    switch(choice) {
        case 1: qsort(hospitals, numHospitals, sizeof(Hospital), compareByPrice); break;
        case 2: qsort(hospitals, numHospitals, sizeof(Hospital), compareByAvailableBeds); break;
        case 3: qsort(hospitals, numHospitals, sizeof(Hospital), compareByName); break;
        case 4: qsort(hospitals, numHospitals, sizeof(Hospital), compareByRating); break;
        default: printf("Invalid choice.\n");
    }
}

void printHospitalsInCity(const char *city) {
    printf("\nHospitals in %s:\n", city);
    for (int i = 0; i < numHospitals; i++) {
        if (strcasecmp(hospitals[i].city, city) == 0) {
            printf("Name: %s\n", hospitals[i].name);
            printf("City: %s\n", hospitals[i].city);
            printf("Available Beds: %d\n", hospitals[i].availableBeds);
            printf("Price per Bed: %d\n", hospitals[i].pricePerBed);
            printf("Rating: %.2f\n", hospitals[i].rating);
            printf("Reviews: %s\n\n", hospitals[i].reviews);
        }
    }
}

int main() {
    // Example data
    strcpy(hospitals[0].name, "Narayana Hrudayalaya");
    strcpy(hospitals[0].city, "Bengaluru");
    hospitals[0].availableBeds = 50;
    hospitals[0].pricePerBed = 2000;
    hospitals[0].rating = 4.5;
    strcpy(hospitals[0].reviews, "Excellent care.");

    strcpy(hospitals[1].name, "Manipal Hospital");
    strcpy(hospitals[1].city, "Bengaluru");
    hospitals[1].availableBeds = 75;
    hospitals[1].pricePerBed = 2200;
    hospitals[1].rating = 4.7;
    strcpy(hospitals[1].reviews, "Highly recommended.");

    strcpy(hospitals[2].name, "Victoria Hospital");
    strcpy(hospitals[2].city, "Bengaluru");
    hospitals[2].availableBeds = 100;
    hospitals[2].pricePerBed = 1800;
    hospitals[2].rating = 4.3;
    strcpy(hospitals[2].reviews, "Good facilities but crowded.");

    strcpy(hospitals[3].name, "Mysuru Medical Center");
    strcpy(hospitals[3].city, "Mysuru");
    hospitals[3].availableBeds = 40;
    hospitals[3].pricePerBed = 1500;
    hospitals[3].rating = 4.1;
    strcpy(hospitals[3].reviews, "Friendly staff and clean environment.");

    strcpy(hospitals[4].name, "Mandya Institute Of Medical Sciences");
    strcpy(hospitals[4].city, "Mandya");
    hospitals[4].availableBeds = 30;
    hospitals[4].pricePerBed = 1600;
    hospitals[4].rating = 4.0;
    strcpy(hospitals[4].reviews, "Good care but limited facilities.");

    numHospitals = 5;

    // Example patient data
    strcpy(patients[0].name, "Raju");
    patients[0].age = 30;
    strcpy(patients[0].disease, "Heart Disease");
    strcpy(patients[0].hospital, "Narayana Hrudayalaya");

    strcpy(patients[1].name, "Abhi");
    patients[1].age = 45;
    strcpy(patients[1].disease, "Asthma");
    strcpy(patients[1].hospital, "Manipal Hospital");

    strcpy(patients[2].name, "Arun");
    patients[2].age = 60;
    strcpy(patients[2].disease, "Diabetes");
    strcpy(patients[2].hospital, "Victoria Hospital");

    strcpy(patients[3].name, "Swathi");
    patients[3].age = 25;
    strcpy(patients[3].disease, "Flu");
    strcpy(patients[3].hospital, "Mysuru Medical Center");

    strcpy(patients[4].name, "Surabhi");
    patients[4].age = 35;
    strcpy(patients[4].disease, "Injury");
    strcpy(patients[4].hospital, "Mandya Institute Of Medical Sciences");

    numPatients = 5;

    int choice;
    while (1) {
        printf("\nHospital Management System Menu:\n");
        printf("1. Print Hospital Data\n");
        printf("2. Print Patient Data\n");
        printf("3. Sort Hospitals\n");
        printf("4. Print Hospitals in City\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printHospitalData(); 
                break;
            case 2: 
                printPatientData(); 
                break;
            case 3:
                printf("\nSort Hospitals By:\n");
                printf("1. Bed Price\n");
                printf("2. Available Beds\n");
                printf("3. Name\n");
                printf("4. Rating\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                sortHospitals(choice);
                printHospitalData();
                break;
            case 4:
                {
                    char city[100];
                    printf("Enter city: ");
                    scanf("%s", city);
                    printHospitalsInCity(city);
                }
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default: 
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
