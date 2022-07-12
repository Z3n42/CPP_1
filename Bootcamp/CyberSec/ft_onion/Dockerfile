# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dokerfile                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 12:14:05 by ingonzal          #+#    #+#              #
#    Updated: 2022/07/12 12:03:32 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Dockerfile

FROM debian
WORKDIR ~/42/Bootcamp/CyberSec/ft_onion  
RUN apt-get update && apt-get install openssh-server -y
RUN apt-get install nginx -y
RUN apt-get install vim
RUN mkdir /var/run/sshd
RUN echo 'root:mypassword' | chpasswd
RUN sed -i 's/PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd
# RUN service nginx start
EXPOSE 80 4242
CMD ["/usr/sbin/sshd", "-D"]

# FROM ubuntu:16.04

# EXPOSE 22
