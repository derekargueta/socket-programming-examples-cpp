#include <stdlib.h>
#include <unistd.h>

#include <iostream>

#include "server.h"

int main(int argc, char** argv) {
  int option;

  // setup default arguments
  int port = 3000;

  // process command line options using getopt()
  // see "man 3 getopt"
  while ((option = getopt(argc, argv, "p:")) != -1) {
    switch (option) {
    case 'p':
      port = atoi(optarg);
      break;
    default:
      std::cout << "server [-p port]" << std::endl;
      exit(EXIT_FAILURE);
    }
  }

  Server server = Server(port);
  server.run();
}
