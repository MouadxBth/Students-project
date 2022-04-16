# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Compilation.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 16:18:04 by mbouthai          #+#    #+#              #
#    Updated: 2022/04/16 17:46:33 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef COMPILATION_MK
	COMPILATION_MK = 1

NAME	= Students

CC	= gcc

CFLAGS	?= -Wall -Werror -Wextra

LDFLAGS ?= 

RM	= rm -f

RMDIR	= rmdir

endif
