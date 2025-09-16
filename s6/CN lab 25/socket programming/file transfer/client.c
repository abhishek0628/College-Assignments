
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 65432
#define BUFFER_SIZE 1024


void receive_file(int sockfd, FILE *fp) {
    char data[BUFFER_SIZE] = {0};

    
    while (1) {
        int n = recv(sockfd, data, BUFFER_SIZE, 0);
        if (n <= 0) {
            break; 
        }
        fprintf(fp, "%s", data);
        bzero(data, BUFFER_SIZE);
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char *server_ip = "127.0.0.1";  
    char filename[BUFFER_SIZE], received_filename[BUFFER_SIZE];

    
    printf("Enter the filename to request from the server: ");
    scanf("%s", filename);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }
    printf("Client socket created.\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        exit(1);
    }
    printf("Connected to server at %s:%d\n", server_ip, PORT);

    
    send(sockfd, filename, sizeof(filename), 0);

    
    printf("Receiving file...\n");
    snprintf(received_filename, sizeof(received_filename), "received_%s", filename);

    
    FILE *fp = fopen(received_filename, "wb");
    if (fp == NULL) {
        perror("File creation failed");
        exit(1);
    }

    
    receive_file(sockfd, fp);
    printf("File received and saved as %s\n", received_filename);

    
    fclose(fp);
    close(sockfd);

    return 0;
}
