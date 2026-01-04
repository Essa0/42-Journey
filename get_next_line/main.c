/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 22:38:41 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/11/07 22:42:14 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int main()
{
	int fd;
	char *line;
    int lineCount = 1;

	fd = open("get_next_line.h", O_RDONLY);
	while((line=get_next_line(fd)) != NULL)
	{
		printf("%d %s", lineCount,line);
		lineCount += 1;
        free(line);
        
	}
	close(fd);
	return (0);
}