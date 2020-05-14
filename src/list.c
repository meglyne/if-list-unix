/* Author: Margot Marc
 * Date: 14/05/2020
 */

/* Use of ifaddrs.h
 * Implements ifaddrs struct and getifaddrs(struct ifaddrs **ifap) procedure 
 * that will be used to list the available network interfaces
 */
#include <ifaddrs.h>

/* Use of sys/socket.h 
 * Implements AF_INET, AF_INET6, AF UNIX and AF_LOCAL names that will be used 
 * to determine the kind of network interface listed
 */
#include <sys/socket.h>

/* Use of netdb.h
 * Implements getnameinfo used to translate an address into a name
 */
#include <netdb.h>

/* Use of stdio.h
 * Implements printf and fprintf procedures for std output management
 */
#include <stdio.h>

/* Use of stdlib.h
 * Implements EXIT_FAILURE and EXIT_SUCCESS names
 */
#include <stdlib.h>

int main(int argc, char **argv)
{
    struct ifaddrs *addresses;
    if (getifaddrs(&addresses) == -1)
    {
        fprintf(stderr, "getifaddrs call failed\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        struct ifaddrs *address = addresses;
        while (address)
        {
            printf("%s\t", address->ifa_name);
            address = address->ifa_next;
        }
        //data returned by getifaddrs is dynamically allocated and should be freed using freeifaddrs()
        freeifaddrs(addresses);
        exit(EXIT_SUCCESS);
    }
}