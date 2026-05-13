*This project has been created as part of the 42 curriculum by iabiesat*

## Description:
The philo (philosophers) problem let say there are N of philo around the same table each one has their own plate,there's \
fork between each pair of them, so to understand it there are for example 5 (philo, plate, fork) the philo's can only \
alternately think and eat, each philo can eat if they have left and right fork. 

## Instructions:
the problem is how to design project that simulate this project and there are no philo should die and u should be carefully to avoid deadlock and race condition

**express the project:**
checked the input user then initialize the table (id's, meals, eat time), for distribute the fork the left 
```C
(*philo)[i].l_fork = &info->fork_mutex[i];
(*philo)[i].r_fork = &info->fork_mutex[(i + 1) % info->num_philo];
```
fork `idx[i]` pointed to his own idx for the left and the right fork is `idx[(i+1) % num_philo]` philo pointed to his neighbor's \
idx for the right fork, and this strategy help us to avoid deadlock, for one philo we take it as a special case to avoid stuck with lock for the same fork

#### why we use pointer for fork instead of take copy? 
**Ans** -> 
used Pointers to pthread_mutex_t because forks are Shared Resources. By using pointers, all philosophers refer to the same \
memory address of the mutex. This allows the Operating System's scheduler to see that multiple threads are competing for the \
exact same lock. If I used copies, each philosopher would have a private mutex, making them unable to 'see' if their neighbor \
has already claimed the fork, which would lead to multiple philosophers eating with the same fork simultaneously (Data Race)

start to create philo's (threads), in this part to be sure that no one appears starved at beginning, we set last_time_eat = start_time
```C
while (i < info->num_philo)
{
	philo[i].last_time_eat = info->start_time;
	i++;
}
```
about distribute the fork for each philo i do it depend on one number of philo if even or odd, the even philo start from right and odd \
start from left this way ensure at least one philo always can be have two fork and this way also help to avoid deadlock

### when the deadlock maybe happen?
the deadlock happen in this case when all of them stuck in close circuit, we solved it by the following.

in config with odd num of philo for ex..`(5, 800, 200, 200)` i face issue where the table can't be divide into equal two groups, this cause \
starvation for philo where one is constantly out-completed by their faster neighbor, to solve it i implement strategy that forced the philo who finished sleep they don't immediately back to the fork, instead the calculate thinking delay based on difference between `time_to_eat` and `time_to_sleep`
```C
static void	philo_think(t_philo *philo)
{
	long long	think_time;

	print_fun(philo, "is thinking");
	// odd number
	if (philo->info->num_philo % 2 == 1)
	{

		think_time = philo->info->time_to_eat - philo->info->time_to_sleep;
		if (think_time <= 0)
			think_time = philo->info->time_to_eat / 2;
		if (think_time > 0)
			ft_usleep(philo, think_time);
	}
}
```
### why `time_to_eat` divide by 2 not time else?
The thinking delay is calculated based on time_to_eat rather than time_to_sleep. This is because the forks are the shared bottleneck, and their availability is strictly tied to the eating duration. By anchoring our thinking rhythm to the resource's occupancy time, we achieve a more stable and predictable scheduling, especially in odd-numbered configurations.

```C
if (philo->id % 2 == 0)
{
	pthread_mutex_lock(philo->r_fork);
	print_fun(philo, "has taken a fork");
	pthread_mutex_lock(philo->l_fork);
}
else
{
	pthread_mutex_lock(philo->l_fork);
	print_fun(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
}
```
The waiter runs in the Main Thread to observe the simulation without the overhead of an extra thread. It acts as the final authority on the simulation's state, ensuring immediate termination upon death.

### Death Detection (Precision Timing):
for each philosopher, the Waiter calculates the time elapsed since their last meal:$$Time\ Since\ Last\ Meal = Current\ Time - Last\ Meal\ Time$$If this value exceeds or equals the time_to_die, the Waiter immediately:Locks the print_mutex to prevent further logs.Updates the global is_dead flag using the dead_mutex.Prints the final "died" message and terminates the simulation.

### memory management:
before freeing any memory, the program must ensure that all philo's have finished their execution, using `pthread_join` for every philo (thread) \
also every initialized mutex is explicitly destroyed using `pthread_mutex_destroy` to be sure that all resources tied to the sync primitives. \
with every test we use `valgrind` tool to help us to detect if there leaks, also use `--tool=helgrind` flag with `valgrind` to be sure there are no data race.

##### requirement to run the project:
- CC compiler
- valgrind if want to check leaks

compilation
```bash
git clone "repo"
cd philo
make
```
example to use
```bash
./philo 1 800 200 200      # Single philosopher
./philo 5 800 200 200      # Basic case
./philo 5 800 200 200 7    # With meal count
./philo 4 410 200 200      # Tight timing
./philo 100 800 200 200    # Stress philosophers
```
invalid arg:
* ./philo 0 800 200 200 (should fail)
* ./philo 5 -1 200 200 (should fail)
* ./philo (wrong arg count, should fail)
## Resources:
https://en.wikipedia.org/wiki/Dining_philosophers_problem
https://c-for-dummies.com/blog/?p=4236
https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3.html
https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2
https://www.youtube.com/watch?v=uA8X5zNOGw8&list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM
https://www.geeksforgeeks.org/c/thread-functions-in-c-c/
https://stackoverflow.com/questions/6984576/zombie-threads-on-posix-systems
https://github.com/mkurkar/philosophers-42/blob/master/EVALUATION_QUESTIONS.md