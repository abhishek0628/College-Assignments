#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 4445
#define BUFFER_SIZE 1024

int client_fd; // Global variable to access in both threads

void *receive_messages(void *arg) {
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Client disconnected.\n");
            break;
        }
        printf("\nClient: %s", buffer);
        printf("Server: "); // Reprint prompt for user
        fflush(stdout);
    }

    close(client_fd);
    pthread_exit(NULL);
}

int main() {
    int server_fd;
    struct sockaddr_in server_addr, client_addr;
    pthread_t recv_thread;

    // Create server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept a client connection
    socklen_t addr_size = sizeof(client_addr);
    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_size);
    if (client_fd < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Client connected.\n");

    // Start receiving messages in a new thread
    pthread_create(&recv_thread, NULL, receive_messages, NULL);

    // Main thread handles sending messages
    char buffer[BUFFER_SIZE];
    while (1) {
        printf("Server: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(client_fd, buffer, strlen(buffer), 0);
    }

    close(server_fd);
    return 0;
}
