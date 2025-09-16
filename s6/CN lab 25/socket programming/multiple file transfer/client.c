
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 65432
#define BUFFER_SIZE 1024

// Function to receive a file
void receive_file(int sockfd, FILE *fp) {
    char data[BUFFER_SIZE] = {0};

    // Receive data and write it to the file
    while (1) {
        int n = recv(sockfd, data, BUFFER_SIZE, 0);
        if (n <= 0) {
            break;  // Exit the loop if no more data is received
        }
        fprintf(fp, "%s", data);
        bzero(data, BUFFER_SIZE);
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char *server_ip = "127.0.0.1";  // Server IP address
    char buffer[BUFFER_SIZE];
    char filenames[10][BUFFER_SIZE];  // Store filenames
    int file_count = 0;

    // Prompt the user to enter the files to be requested
    printf("Enter the command to request files (e.g., 'file1,file2,file3'): ");
    fgets(buffer, sizeof(buffer), stdin);

    // Remove newline character from input
    buffer[strcspn(buffer, "\n")] = 0;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }
    printf("Client socket created.\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        exit(1);
    }
    printf("Connected to server at %s:%d\n", server_ip, PORT);

    // Send the "Send filename1,filename2" string to the server
    send(sockfd, buffer, sizeof(buffer), 0);

    // Parse the filenames from the command string (split by commas)
    char *filename = strtok(buffer, ",");
    while (filename != NULL) {
        strcpy(filenames[file_count], filename);
        file_count++;
        filename = strtok(NULL, ",");
    }

    // Receive and save each file
    for (int i = 0; i < file_count; i++) {
        char received_filename[BUFFER_SIZE];
        snprintf(received_filename, sizeof(received_filename), "received_%s", filenames[i]);

        FILE *fp = fopen(received_filename, "wb");
        if (fp == NULL) {
            perror("File creation failed");
            exit(1);
        }

        printf("Receiving file %d...\n", i + 1);
        receive_file(sockfd, fp);
        printf("File received and saved as %s\n", received_filename);

        fclose(fp);
    }

    // Close the socket
    close(sockfd);

    return 0;
}
