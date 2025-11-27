#include <stdio.h>
#include <string.h>

#define MAX 50

struct Player {
    int id;
    char name[50];
    char country[50];
    int age;
    char role[30];
    float rating;
};

struct Player players[MAX];
int count = 0;

void addPlayer() {
    if (count >= MAX) {
        printf("Maximum player limit reached!\n");
        return;
    }

    struct Player p;
    printf("\n--- Add Player ---\n");
    printf("Enter ID: ");
    scanf("%d", &p.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter Country: ");
    scanf(" %[^\n]", p.country);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter Role: ");
    scanf(" %[^\n]", p.role);
    printf("Enter Rating: ");
    scanf("%f", &p.rating);

    players[count++] = p;
    printf("Player added successfully!\n");
}

void displayPlayers() {
    if (count == 0) {
        printf("\nNo players to display!\n");
        return;
    }

    printf("\n--- Player List ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nPlayer %d\n", i + 1);
        printf("ID       : %d\n", players[i].id);
        printf("Name     : %s\n", players[i].name);
        printf("Country  : %s\n", players[i].country);
        printf("Age      : %d\n", players[i].age);
        printf("Role     : %s\n", players[i].role);
        printf("Rating   : %.2f\n", players[i].rating);
    }
}

int searchPlayer(int id) {
    for (int i = 0; i < count; i++) {
        if (players[i].id == id)
            return i;
    }
    return -1;
}

void searchPlayerByID() {
    int id;
    printf("\nEnter Player ID to search: ");
    scanf("%d", &id);

    int index = searchPlayer(id);
    if (index == -1) {
        printf("Player not found!\n");
    } else {
        printf("\n--- Player Found ---\n");
        printf("ID       : %d\n", players[index].id);
        printf("Name     : %s\n", players[index].name);
        printf("Country  : %s\n", players[index].country);
        printf("Age      : %d\n", players[index].age);
        printf("Role     : %s\n", players[index].role);
        printf("Rating   : %.2f\n", players[index].rating);
    }
}

void updatePlayer() {
    int id;
    printf("\nEnter Player ID to update: ");
    scanf("%d", &id);

    int index = searchPlayer(id);
    if (index == -1) {
        printf("Player not found!\n");
        return;
    }

    printf("\n--- Update Player ---\n");
    printf("Enter New Name: ");
    scanf(" %[^\n]", players[index].name);
    printf("Enter New Country: ");
    scanf(" %[^\n]", players[index].country);
    printf("Enter New Age: ");
    scanf("%d", &players[index].age);
    printf("Enter New Role: ");
    scanf(" %[^\n]", players[index].role);
    printf("Enter New Rating: ");
    scanf("%f", &players[index].rating);

    printf("Player updated successfully!\n");
}

void deletePlayer() {
    int id;
    printf("\nEnter Player ID to delete: ");
    scanf("%d", &id);

    int index = searchPlayer(id);
    if (index == -1) {
        printf("Player not found!\n");
        return;
    }

    for (int i = index; i < count - 1; i++) {
        players[i] = players[i + 1];
    }
    count--;

    printf("Player deleted successfully!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Player Profile Management =====\n");
        printf("1. Add Player\n");
        printf("2. Display Players\n");
        printf("3. Search Player by ID\n");
        printf("4. Update Player\n");
        printf("5. Delete Player\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPlayer(); break;
            case 2: displayPlayers(); break;
            case 3: searchPlayerByID(); break;
            case 4: updatePlayer(); break;
            case 5: deletePlayer(); break;
            case 6: 
                printf("Exiting...\n");
                return 0;
            default: 
                printf("Invalid choice! Try again.\n");
        }
    }
}
