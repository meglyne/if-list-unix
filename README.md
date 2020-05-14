# if-list-unix

## Presentation

This is a C program made for UNIX-like operating systems that lists network interfaces.

## TODO

- Add informations about the sockets (format of address structure) using sa_data information. - done
- Display IPv4 and IPv6 addresses if available.
- Add an option to filter out any socket that does not use IPv4 or IPv6.

## Sources for writing the code

### man pages

- `getifaddrs(3)`
- `socket(2)`
- `getnameinfo(3)`
