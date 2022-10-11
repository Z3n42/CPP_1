FROM ubuntu:18.04

RUN apt-get update && apt-get install -y \
    man \
    clang \
    gcc \
    make \
    vim \
    git \
    curl \
    wget \
    zsh \
    valgrind \
    gdb 

# RUN  sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" --unattended
# Default powerline10k theme, no plugins installed
RUN sh -c "$(wget -O- https://github.com/deluan/zsh-in-docker/releases/download/v1.1.2/zsh-in-docker.sh)" --unattended

# COPY ~/.cache /root
# COPY ~/.oh-my-zsh /root
# COPY ~/.p10k.zsh /root
# COPY ~/Docker_Valgrind/config/.shell.pre-oh-my-zsh /root
# COPY ~/.vim /root
# COPY ~/.viminfo /root
# COPY ~/.vimrc /root
# COPY ~/.zsh_history /root
# COPY ~/.zshrc /root

WORKDIR /valgrind

ENTRYPOINT "zsh"
