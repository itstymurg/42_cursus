#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

typedef struct s_philo
{
	pthread_t       t1;
	int          	id;
	int             life_status;
	int             eat_status;
	int             sleep_status;
	int             number_of_meals;
	int             forks;
	uint64_t        time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	struct s_game	*game;
}   t_philo;

typedef struct s_game
{
	int 			n_philo;
	int 			n_meals;
	t_philo 		*philosopers;
	int             dead;
	int             finished;
	u_int64_t       death_time;
	u_int64_t       eat_time;
	u_int64_t       sleep_time;
	u_int64_t       start_time;
	pthread_mutex_t *forks;
	pthread_mutex_t lock;
	pthread_mutex_t write;
}   t_game;

int	ft_atoi(const char *str);

# endif