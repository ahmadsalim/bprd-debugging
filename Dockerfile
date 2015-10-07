# Dockerfile for BPRD Debugging Exercise

# Use ubuntu as base
FROM registry.hub.docker.com/_/ubuntu/

# Dependencies according to 'fbinfer.com' README

RUN add-apt-repository ppa:ubuntu-toolchain-r/test && \
    apt-get update && \
    apt-get install -y build-essential \
                       git \
                       libgmp-dev \
                       libmpc-dev \
                       libmpfr-dev \
                       m4 \
                       openjdk-7-jdk \
                       python-software-properties \
                       unzip \
                       zlib1g-dev \

RUN wget https://github.com/ocaml/opam/releases/download/1.2.2/opam-1.2.2-x86_64-Linux -O opam && \
    chmod +x opam && \
    ./opam init -y --comp=4.01.0 && \
    eval `./opam config env` && \
    ./opam install -y extlib.1.5.4 atdgen.1.6.0 javalib.2.3.1 sawja.1.5.1

RUN wget https://github.com/facebook/infer/releases/download/v0.3.0/infer-linux64-v0.3.0.tar.xz && \
    tar xf infer-*-v0.3.0.tar.xz && \
    cd infer-*-v0.3.0 && \
    make -C infer && \
    (echo "export PATH=$(pwd)/infer/bin:'$PATH'" >> /etc/profile)

RUN mkdir /data && \
    cd /data

ADD *.c *.h /data

CMD ["/usr/bin/bash"]
