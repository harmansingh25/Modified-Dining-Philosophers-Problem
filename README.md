# Modified-Dining-Philosophers-Problem

Promt: 

The pthread library provides the pthread mutex structure to enable easy mutual exclusion. Design a counting semaphore structure using mutex called
my semaphore so that multiple pthreads can synchronize access to some limited/shared resource. Note that the counting semaphore should use the signalling mechanism the way semaphores work, i.e. signalling a thread that waits on a semaphore. Your counting semaphore should implement the primitives
wait(), signal() and signal(printValue) for debugging.

Use the semaphore you have so defined to solve the following modified version
of dining philosopher problem. Consider the scenario where you have a similar
case of k philosophers and k forks. But in this case, the dinning table also has a
pair of sauce bowls, both of which are needed simultaneously for a philosopher
to eat. 

Write a program that simulates the philosophers using threads, and
the resources (forks and sauce bowls) using a shared variable. Your simulation
should print the following message on the console whenever a philosopher gets
to eat: ”Philosopher < thread id > eats using forks < fork no x > and <
fork no y >.

The simulation keeps running in an infinite loop. Then, use
my semaphore to avoid any possible deadlocks. You may also implement non-
blocking variants of wait() and signal() using the non-blocking functions
available in the Pthreads library.

# Check Writeup_2019042.pdf for implementation details
