/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:21:25 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/10 16:48:27 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

double	find_delta(double coefdir, double ordo, double rayon)
{
	double	result;
	// calcul du discriminant de l'équation du second degré (b²-4ac)
	/*					B								A							C*/
	result = pow(2 * ordo * coefdir, 2) - 4 * (1 + pow(coefdir, 2)) * (pow(ordo, 2) - pow(rayon, 2));
	return (result);
}

void intersection(double ax, double ay, double bx, double by, double rayon) {
	double	coefdir;
	double	ordo;
	double	delta;

	// calcul du coefficient directeur de la droite
	coefdir = (by - ay) / (bx - ax);
	// calcul de l'ordonnée à l'origine de la droite
	ordo = ay - coefdir * ax;
	delta = find_delta(coefdir, ordo, rayon);
	if (delta < 0)
		printf("Pas de point d'intersection.\n");
	else if (delta > 0)
	{
		/*			ici (-b + sqrt(delta))/2a et (-b - sqrt(delta))/2a			*/
		double x1 = (-2 * ordo * coefdir + sqrt(delta)) / (2 * (1 + pow(coefdir, 2)));
		double y1 = coefdir * x1 + ordo;
		double x2 = (-2 * ordo * coefdir - sqrt(delta)) / (2 * (1 + pow(coefdir, 2)));
		double y2 = coefdir * x2 + ordo;
		printf("Points d'intersection : (%f, %f) et (%f, %f)\n", x1, y1, x2, y2);
	}
	else
	{
		/*					ici -b/2a							*/
		double x = -2 * ordo * coefdir / (2 * (1 + pow(coefdir, 2)));
		double y = coefdir * x + ordo;
		printf("Point d'intersection : (%lf, %lf)\n", x, y);
	}
}

int	main()
{
	char	line[1024];
	double	Ax;
	double	Ay;
	double	Bx;
	double	By;
	double	r;

	printf ("entrer Ax : ");
	fgets(line, 1024, stdin);
	Ax = atof(line);
	printf ("entrer Ay : ");
	fgets(line, 1024, stdin);
	Ay = atof(line);
	printf ("entrer Bx : ");
	fgets(line, 1024, stdin);
	Bx = atof(line);
	printf ("entrer By : ");
	fgets(line, 1024, stdin);
	By = atof(line);
	printf ("entrer rayon : ");
	fgets(line, 1024, stdin);
	r = atof(line);
	printf("pour a=(%f, %f), b=(%f, %f) et rayon = %f\n", Ax, Ay, Bx, By, r);
	intersection(Ax, Ay, Bx, By, r);
}
