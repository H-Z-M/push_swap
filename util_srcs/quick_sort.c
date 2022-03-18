/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:15:46 by sudatsu           #+#    #+#             */
/*   Updated: 2022/03/16 22:18:18 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

/* void	swap(int *x, int *y) */
/* { */
/* 	int	tmp; */
/*  */
/* 	tmp = *y; */
/* 	*y = *x; */
/* 	*x = tmp; */
/* } */
/*  */
/* bool	find_pivot(int sort_stack[], int first, int last, int *pivot) */
/* { */
/* 	while (first < last) */
/* 	{ */
/* 		if (sort_stack[first] > sort_stack[first + 1]) */
/* 		{ */
/* 			*pivot = sort_stack[first]; */
/* 			return (false); */
/* 		} */
/* 		if (sort_stack[first] < sort_stack[first + 1]) */
/* 		{ */
/* 			*pivot = sort_stack[first + 1]; */
/* 			return (false); */
/* 		} */
/* 		first++; */
/* 	} */
/* 	return (true); */
/* } */
/*  */
/* bool	partition(int sort_stack[], int first, int last, int *pivot) */
/* { */
/* 	int		i; */
/* 	int		j; */
/*  */
/* 	i = first; */
/* 	j = last; */
/* 	if (find_pivot(sort_stack, first, last, pivot)) */
/* 		return (true); */
/* 	while (1) */
/* 	{ */
/* 		while (i < last && sort_stack[i] < *pivot) */
/* 			i++; */
/* 		while (first < j && *pivot <= sort_stack[j]) */
/* 			j--; */
/* 		if (i >= j) */
/* 			break ; */
/* 		swap(&sort_stack[i], &sort_stack[j]); */
/* 	} */
/* 	*pivot = i; */
/* 	return (false); */
/* } */
/*  */
/* void	quick_sort(int sort_stack[], int first, int last) */
/* { */
/* 	int		pivot; */
/*  */
/* 	if (first >= last) */
/* 		return ; */
/* 	if (partition(sort_stack, first, last, &pivot)) */
/* 		return ; */
/* 	quick_sort(sort_stack, first, pivot - 1); */
/* 	quick_sort(sort_stack, pivot, last); */
/* } */

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
