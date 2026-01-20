*This project has been created as part of the 42 curriculum by iabiesat*

## Description:
**Minitalk** is a small communication program that enables data exchange between a **server** and a **client** using **POSIX signals**.

he communication protocol is based on sending messages using only two UNIX signals:
- `SIGUSR1`
- `SIGUSR2`

each character is encoded in binary and transmitted from the client to the server through a sequence of signals the server reconstructs the bits into characters and displays the received message

this project focuses on understanding inter-process communication without using sockets, pipes, or shared memory

## Instructions

**requirements**
- GCC or Clang
- Make

clone the repo and compile using **make** \
you need two terminal\
` ./server ` \
expected output: server pid: 22115 \
open other terminal and run \
` ./client <pid> message`\
example: \
`./client 22115 "hello world"`

## Resources

- student note
- https://42-cursus.gitbook.io/guide/2-rank-02/minitalk/understand-minitalk
- https://www.geeksforgeeks.org/c/signals-c-language/
- linux man

## About using AI:
AI tool such as (chatgpt, claude and copilot) to create general roadmap on how to start and what should to learn and to organize the program, also it was helpful with bug that i faced during build the program