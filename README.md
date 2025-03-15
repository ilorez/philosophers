# Philosophers

## Introduction
Philosophers is a project from the 42 curriculum that explores concurrency, multithreading, and synchronization problems. The goal is to simulate the classic **Dining Philosophers Problem**, which demonstrates issues related to resource sharing and deadlocks.

## The Dining Philosophers Problem
The problem consists of **N** philosophers sitting around a circular table with **N** forks. Each philosopher follows a cycle of **thinking**, **eating**, and **sleeping**. To eat, a philosopher must acquire two forks (one on their left and one on their right). The challenge is to avoid race conditions, deadlocks, and starvation while ensuring that the simulation runs correctly.

## Objectives
- Implement a simulation of the dining philosophers problem.
- Use **threads** to represent each philosopher.
- Use **mutexes** or **semaphores** to manage access to shared resources (forks).
- Ensure no philosopher starves.
- Avoid deadlocks and race conditions.

## Mandatory Part
You must create a program that follows these rules:
- Each philosopher is a separate thread.
- A philosopher can only eat if they acquire both forks.
- If a philosopher does not eat within a given time, they die.
- The program stops when a philosopher dies or when a specified number of meals has been reached.

## Bonus Part
- Implement the solution using **semaphores** instead of mutexes.
- Philosophers as processes instead of threads.

## Concepts Covered
- **Multithreading**: Managing multiple philosophers simultaneously.
- **Synchronization**: Controlling shared resources with mutexes or semaphores.
- **Concurrency Issues**: Preventing race conditions, deadlocks, and starvation.

## Usage
To compile and run the project:
```sh
make
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_meals]
```

Example:
```sh
./philo 5 800 200 200
```
This command starts a simulation with **5 philosophers**, where:
- Each philosopher dies if they don’t eat within **800ms**.
- Eating takes **200ms**.
- Sleeping takes **200ms**.

## Notes
- The project requires a deep understanding of **threads**, **mutexes**, and **timing**.
- Proper synchronization is critical to prevent **deadlocks** and ensure correctness.
- Debugging multithreaded applications can be challenging; tools like **gdb** or **helgrind** (from Valgrind) can help.

## Resources
- [Dining Philosophers Problem - Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [42 School Subject PDF](./en.subject.pdf)

