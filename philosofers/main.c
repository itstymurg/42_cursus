#include "philosophers.h"

void	check_args(int argc)
{
	if (argc < 5 || argc > 6)
	{
		write(2, "ERROR\n", 6);
		exit (0);
	}
}

void	init(t_game *g, char *argv[])
{
	g->n_philo = ft_atoi(argv[1]);
	if (g->n_philo > 200)
	{
		printf ("Demasiados filosofos\n");
		exit(0);
	}
	g->death_time = ft_atoi(argv[2]);
	g->eat_time = ft_atoi(argv[3]);
	g->sleep_time = ft_atoi(argv[4]);
	if  (argv[5])
		g->n_meals = ft_atoi(argv[5]);
	else
		g->n_meals = -1;
	pthread_mutex_init(&g->lock, NULL);
	pthread_mutex_init(&g->write, NULL);
	g->philosopers = malloc (sizeof(t_philo) * g->n_philo);
}

void	eat()
{

}

void	think()
{

}

void	sleeping()
{

}

void	*routine(void	*p)
{
	t_philo *philos;

	philos = p;
	eat();
	sleeping();
	think();
}

void	philos_init(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->n_philo)
	{
		pthread_create(&g->philosopers[i].t1, NULL, &routine, g->philosopers);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_game	g;
	check_args(argc);
	init(&g, argv);
	
	printf("%d\n", g.n_philo);
	
}