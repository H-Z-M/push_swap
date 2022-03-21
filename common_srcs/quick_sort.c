/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:15:46 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/21 08:53:45 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

int	partition(int array[], int l, int r)
{
	int	i;
	int	j;
	int	pivot;

	pivot = array[r];
	i = (l - 1);
	j = l;
	while (j <= r - 1)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
		j++;
	}
	swap(&array[i + 1], &array[r]);
	return (i + 1);
}

void	quick_sort(int array[], int l, int r)
{
	int	pivot;

	if (l < r)
	{
		pivot = partition(array, l, r);
		quick_sort(array, l, pivot - 1);
		quick_sort(array, pivot + 1, r);
	}
}
