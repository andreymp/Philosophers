# Philosophers (42 project)
I’ve never thought philosophy would be so deadly
## Description
In this project, it was learned the basics of threading a process. It was learned how to make threads and was discovered the mutex. \
This project contains **The Dining Philosopher Problem** but a littile bit modified: \
Program can have any number of philosophers uder 200, also philosophers can sleep in this program.
## Game rules
• The philosophers must never be starving. \
• Every philosopher needs to eat. \
• Philosophers don’t speak with each other. \
• Philosophers don’t know when another philosopher is about to die. \
• Each time a philosopher has finished eating, he will drop his forks and start sleeping. \
• When a philosopher is done sleeping, he will start thinking. \
• The simulation stops when a philosopher dies. \
• One fork between each philosopher, therefore if they are multiple philosophers, there will be a fork at the right and the left of each philosopher. \
• Each philosopher should be a thread.
## Launching
Run `make` to compile the project. \
Then run `./philo  number_of_philosophers time_to_die time_to_eat time_to_sleep` where all time must be in ms. 
1. number_of_philosophers: is the number of philosophers and also the number of forks.
2. time_to_die: is time each philosopher must ate 
3. time_to_eat: is the time it takes for a philosopher to eat.
4. time_to_sleep: is the time the philosopher will spend sleeping.

Or run `./philo  number_of_philosophers time_to_die time_to_eat time_to_sleep number_of_times_each_philosopher_must_eat` where \
number_of_times_each_philosopher_must_eat is the number each philosopher should eat and then simulation stops.  
