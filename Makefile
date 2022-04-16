# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 15:36:27 by mbouthai          #+#    #+#              #
#    Updated: 2022/04/16 17:48:29 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE_DIR= build/

include $(MAKE_DIR)Settings.mk

include $(MAKE_DIR)Compilation.mk

CFLAGS	+= -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR):
	@mkdir -p $@

$(OBJS): | $(OBJ_DIR)

$(OBJS): $(OBJ_DIR)%.o: $(SRC_DIR)%
	$(CC) $(CFLAGS) -c $< -o $@

$(DEP_DIR):
	@mkdir -p $@

$(DEPS): | $(DEP_DIR)

$(DEPS): $(DEP_DIR)%.d: $(SRC_DIR)%
	$(CC) $(CFLAGS) -MM -MF $@ -MT "$(OBJ_DIR)*.o $@" $<

cleanobj:
	$(RM) $(wildcard $(OBJS))

cleanobjdir: cleanobj
	$(RMDIR) $(OBJ_DIR)

cleandep:
	$(RM) $(wildcard $(DEPS))

cleandepdir: cleandep
	$(RMDIR) $(DEP_DIR)

clean: cleanobjdir cleandepdir

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY = all cleanobj cleanobjdir cleandep cleandepdir clean fclean
