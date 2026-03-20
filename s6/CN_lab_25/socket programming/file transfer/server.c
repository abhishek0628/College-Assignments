
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 65432
#define BUFFER_SIZE 1024


void send_file(FILE *fp, int sockfd) {
    char data[BUFFER_SIZE] = {0};

    
    while (fgets(data, BUFFER_SIZE, fp) != NULL) {
        if (send(sockfd, data, sizeof(data), 0) == -1) {
            perror("Error sending file");
            exit(1);
        }
        bzero(data, BUFFER_SIZE);
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char filename[BUFFER_SIZE];

   
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
        exit(1);
    }
    printf("Server socket created.\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = PORT;

    
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    
    if (listen(server_fd, 10) == 0) {
        printf("Server listening on port %d\n", PORT);
    } else {
        perror("Listen failed");
        exit(1);
    }

    addr_size = sizeof(client_addr);
    new_socket = accept(server_fd, (struct sockaddr*)&client_addr, &addr_size);
    if (new_socket < 0) {
        perror("Server accept failed");
        exit(1);
    }
    printf("Connection accepted from client.\n");

   
    recv(new_socket, filename, sizeof(filename), 0);
    printf("Client requested file: %s\n", filename);

  
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("File not found");
        send(new_socket, "File not found", 15, 0);
    } else {
        
        send_file(fp, new_socket);
        printf("File %s sent to the client.\n", filename);
    }

    
    fclose(fp);
    close(new_socket);
    close(server_fd);

    return 0;
}
