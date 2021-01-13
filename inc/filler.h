/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:11:32 by ahel-men          #+#    #+#             */
/*   Updated: 2020/11/08 12:32:12 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef enum				e_bool
{
	FALSE,
	TRUE
}							t_bool;

typedef struct				s_filler
{
	t_bool					checked;
	char					**map;
	char					**piece;
	int						**int_map;
	int						**asterisks_xy;
	int						asterisks_counter;
	int						player;
	int						first_width;
	int						first_height;
	int						map_width;
	int						map_height;
	int						p_width;
	int						p_height;
	int						index;
	int						h_map_index;
	int						h_piece_index;
	int						score;
	int						save_smallest_score;
	int						on_top_of_one;
	int						w;
	int						z;
	int						save_x;
	int						save_y;
	int						best_x;
	int						best_y;
}							t_filler;

int							ft_is_bad_dimention(t_filler fill);
int							ft_is_max_int_or_negative(int height, int width);
int							ft_free_2d_array(char **tab);
int							ft_detect_demensions_error(int height, int width,
								char **line);
void						ft_fill_map_with_zeros(t_filler *fill);
void						ft_fill_map_with_numbers(t_filler *fill);
void						ft_store_piece_demensions(t_filler *fill,
								char *line, int i, int y);
void						ft_create_hit_map(t_filler *fill);
int							look_for_zero(t_filler *fill);
void						ft_free_2d_int_array(int **tab, int size);
int							ft_stock_asterisks_dimensions(t_filler *fill);
int							ft_get_dimensions_to_place_piece(t_filler *fill);
void						ft_rescue_memory(t_filler *fill);
int							ft_check_which_player(t_filler *fill, char *line,
								t_bool *checked);
int							ft_check_dimensions(t_filler *fill, char *line);
int							store_map(t_filler *fill, char **line);
char						**allocate_char_2d_array(int heigth, int width);
int							ft_stock_map(char *line, t_filler *fill);
void						ft_store_map_demensions(t_filler *fill, char *line,
								int i, int y);
int							ft_define_number(char *str, t_filler *fill);
int							ft_allocate_piece(t_filler *fill,
								char **line, int *i);
int							ft_allocate_map_array(t_filler *fill, char **line);
int							ft_stock_piece(char *line, t_filler *fill);
void						ft_put_my_player(t_filler *fill);

#endif
