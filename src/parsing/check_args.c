/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:02:13 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/07 17:55:24 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Validate the number and type of args passed to the program
// Return (nothing);

void	check_argc(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_extension(argv[1], ".cub"))
			print_error("Wrong map extension\n");
	}
	else if (argc == 1)
		print_error("Missing map file\n");
	else if (argc > 2)
		print_error("Too many arguments\n");
}

// Verifies if the given file has the correct .cub extension
// Return: (0) if the extension matches
//         (1) if the extension does not match

int	check_extension(char *filename, char *extension)
{
	int len;
	int extension_len;

	len = ft_strlen(filename);
	extension_len = ft_strlen(extension);
	while ((filename[len] == extension[extension_len]) && len > 0)
	{
		if (extension_len == 0)
			return (EXIT_SUCCESS);
		len--;
		extension_len--;
	}
	return (EXIT_FAILURE);
}