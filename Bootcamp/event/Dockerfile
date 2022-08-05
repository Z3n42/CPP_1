FROM debian:buster

RUN apt -y update && \
	apt -y install wget build-essential netcat git python3 python3-pip wfuzz dnsutils whois && \
	apt -y upgrade

RUN git clone https://github.com/aboul3la/Sublist3r.git && pip3 install -r /Sublist3r/requirements.txt
RUN git clone https://github.com/danielmiessler/SecLists.git
RUN wget https://go.dev/dl/go1.19.linux-amd64.tar.gz
RUN rm -rf /usr/local/go && tar -C /usr/local -xzf go1.19.linux-amd64.tar.gz
RUN /usr/local/go/bin/go install -v github.com/projectdiscovery/nuclei/v2/cmd/nuclei@latest
RUN export PATH=$PATH:/usr/local/go/bin:/root/go/bin

CMD ["/bin/bash"]
