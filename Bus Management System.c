#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Bus {
    int bus_id;
    char bus_name[50];
    char source[30];
    char destination[30];
    int total_seats;
    int booked_seats;
};

// Function to add a bus
void addBus() {
    struct Bus b;
    FILE *fp = fopen("buses.dat", "ab");
    
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Bus ID: ");
    scanf("%d", &b.bus_id);
    getchar();  // To consume newline character left by scanf
    printf("Enter Bus Name: ");
    fgets(b.bus_name, sizeof(b.bus_name), stdin);
    b.bus_name[strcspn(b.bus_name, "\n")] = '\0';  // Remove trailing newline
    printf("Enter Source: ");
    fgets(b.source, sizeof(b.source), stdin);
    b.source[strcspn(b.source, "\n")] = '\0';
    printf("Enter Destination: ");
    fgets(b.destination, sizeof(b.destination), stdin);
    b.destination[strcspn(b.destination, "\n")] = '\0';
    printf("Enter Total Seats: ");
    scanf("%d", &b.total_seats);
    b.booked_seats = 0;

    fwrite(&b, sizeof(struct Bus), 1, fp);
    fclose(fp);

    printf("Bus added successfully!\n");
}

// Function to display available buses
void displayBuses() {
    struct Bus b;
    FILE *fp = fopen("buses.dat", "rb");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nAvailable Buses:\n");
    printf("ID\tName\tSource\tDestination\tSeats Available\n");

    while (fread(&b, sizeof(struct Bus), 1, fp)) {
        printf("%d\t%s\t%s\t%s\t\t%d\n", b.bus_id, b.bus_name, b.source, b.destination, b.total_seats - b.booked_seats);
    }
    fclose(fp);
}

// Function to book a ticket
void bookTicket() {
    int id, found = 0;
    struct Bus b;
    FILE *fp = fopen("buses.dat", "rb+");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Bus ID to book a ticket: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(struct Bus), 1, fp)) {
        if (b.bus_id == id) {
            found = 1;
            if (b.booked_seats < b.total_seats) {
                b.booked_seats++;
                fseek(fp, -sizeof(struct Bus), SEEK_CUR);
                fwrite(&b, sizeof(struct Bus), 1, fp);
                printf("Ticket booked successfully!\n");
            } else {
                printf("No available seats on this bus.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Bus ID not found.\n");
    }

    fclose(fp);
}

// Function to cancel a ticket
void cancelTicket() {
    int id, found = 0;
    struct Bus b;
    FILE *fp = fopen("buses.dat", "rb+");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Bus ID to cancel a ticket: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(struct Bus), 1, fp)) {
        if (b.bus_id == id) {
            found = 1;
            if (b.booked_seats > 0) {
                b.booked_seats--;
                fseek(fp, -sizeof(struct Bus), SEEK_CUR);
                fwrite(&b, sizeof(struct Bus), 1, fp);
                printf("Ticket cancelled successfully!\n");
            } else {
                printf("No booked tickets to cancel.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Bus ID not found.\n");
    }

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\nBus Management System\n");
        printf("1. Add Bus\n");
        printf("2. Display Buses\n");
        printf("3. Book Ticket\n");
        printf("4. Cancel Ticket\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBus(); break;
            case 2: displayBuses(); break;
            case 3: bookTicket(); break;
            case 4: cancelTicket(); break;
            case 5: exit(0);
            default: printf("Invalid choice, try again.\n");
        }
    }
    
    return 0;
}

