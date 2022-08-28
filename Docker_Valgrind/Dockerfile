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

# COPY ~/.bash_history /root
# COPY ~/.shell* /root
# COPY /Users/ingonzal/.oh-my* /root
# COPY /Users/ingonzal/.p10k* /root
# COPY /Users/ingonzal/.vim* /root
# COPY /Users/ingonzal/.zsh* /root

WORKDIR /valgrind

ENTRYPOINT "zsh"
