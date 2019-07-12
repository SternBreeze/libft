/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_service.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:09:58 by jjacobso          #+#    #+#             */
/*   Updated: 2019/07/04 16:00:39 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		rb_recursive_print(t_rb_tree *t, int iter)
{
	if (t)
	{
		iter += 1;
		rb_recursive_print(t->right, iter);
		int i = iter;
		while (i--)
			write(1, "      ", 5);
		if (t->clr == R)
			ft_printf(RED"%d\n"RESET,*(int*)t->data);
		else
			ft_printf("%d\n", *(int*)t->data);
		rb_recursive_print(t->left, iter);
	}
}

void		rb_print(t_rb_tree *t)
{
	rb_recursive_print(t, 0);
}

void			rb_set_left(t_rb_tree *t, t_rb_tree *l)
{
	if (t)
	{
		t->left = l;
		if (l)
			l->parent = t;
	}
}

void			rb_set_right(t_rb_tree *t, t_rb_tree *r)
{
	if (t)
	{
		t->right = r;
		if (r)
			r->parent = t;
	}
}

t_rb_tree	*rb_left(t_rb_tree *t)
{
	return (t ? t->left : NULL);
}

t_rb_tree	*rb_right(t_rb_tree *t)
{
	return (t ? t->right : NULL);
}

int			rb_is_red(t_rb_tree *t)
{
	return (t ? t->clr == R : 0);
}

int			rb_is_black(t_rb_tree *t)
{
	return (t ? t->clr == B : 0);
}

void			rb_backtrack(t_rb_tree **root)
{
	if (!*root)
		return ;
	while((*root)->parent)
		(*root) = (*root)->parent;
	(*root)->clr = B;
}

int				rb_set_parent_link(t_rb_tree *t, t_rb_tree *ptr)
{
	if (!t || !t->parent)
		return (0);
	if (t->parent->left == t)
		rb_set_left(t->parent, ptr);
	else
		rb_set_right(t->parent, ptr);
	return (1);
}
