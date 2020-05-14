/* Author: Margot Marc
 * Date: 14/05/2020
 */

/* Use of ifaddrs.h
 * Implements ifaddrs struct and getifaddrs(struct ifaddrs **ifap) procedure 
 * that will be used to list the available network interfaces
 */
#include <ifaddrs.h>

/* Use of sys/socket.h 
 * Implements AF_INET, AF_INET6, AF_UNIX and AF_LOCAL names that will be used 
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
            char* family_name;
            int family = address->ifa_addr->sa_family;
            switch(family)
            {
                case AF_INET:   //safamily 2
                    family_name = "AF_INET";
                    break;
                case AF_INET6:  //safamily 10
                    family_name = "AF_INET6";
                    break;
                case AF_PACKET: //sa_family 17
                    family_name = "AF_PACKET";
                    break;
                default:
                    family_name = "???";
                    break;
            }
            printf("%s\t", address->ifa_name);
            printf("%s (%d)\n",family_name,family);
            address = address->ifa_next;
        }
        //data returned by getifaddrs is dynamically allocated and should be freed using freeifaddrs()
        freeifaddrs(addresses);
        exit(EXIT_SUCCESS);
    }
}