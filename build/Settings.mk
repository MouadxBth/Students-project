# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Settings.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 16:21:18 by mbouthai          #+#    #+#              #
#    Updated: 2022/04/16 17:50:40 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef SETTINGS_MK
	SETTINGS_MK = 1

INC_DIR	= inc/

SRC_DIR	= src/

OBJ_DIR	= obj/

DEP_DIR	= dep/

INCLUDES= students.h

SOURCES	= students_input.c students_output.c \
	  students_operations.c students_utils.c \
	  students.c

INCS	= $(addprefix $(INC_DIR), $(INCLUDES))

SRCS	= $(addprefix $(SRC_DIR), $(SOURCES))

OBJS	= $(addprefix $(OBJ_DIR), $(notdir $(SRCS:%=%.o)))

DEPS	= $(addprefix $(DEP_DIR), $(notdir $(SRCS:%=%.d)))

endif
