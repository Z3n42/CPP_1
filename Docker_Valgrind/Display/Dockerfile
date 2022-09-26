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
    gdb \
    xorg \
    libxext-dev \
    zlib1g-dev \
    libbsd-dev

# RUN  sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" --unattended
# Default powerline10k theme, no plugins installed
RUN sh -c "$(wget -O- https://github.com/deluan/zsh-in-docker/releases/download/v1.1.2/zsh-in-docker.sh)" --unattended

RUN git clone https://github.com/42Paris/minilibx-linux.git /valgrind/mlx_linux 

# RUN sh /valgrind/mlx_linux/configure

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
