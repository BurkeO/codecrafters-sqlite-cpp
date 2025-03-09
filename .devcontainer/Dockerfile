FROM ubuntu:latest

# Install prerequisites
RUN apt-get update && apt-get install -y \
    software-properties-common \
    wget \
    curl \
    gnupg \
    git \
    unzip \
    python3-pip

RUN apt-get install -y build-essential
# Add LLVM repo
RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -
RUN add-apt-repository "deb http://apt.llvm.org/focal/ llvm-toolchain-focal main"
RUN apt-get update

# Install latest GCC and G++ compilers
RUN apt-get install -y \
    gcc \
    g++ \
    clang-tools
RUN apt-get install gcc-14 -y
RUN apt-get install g++-14 -y
RUN apt-get install ninja-build -y

# Install latest Python
RUN add-apt-repository ppa:deadsnakes/ppa
RUN apt-get update
RUN apt-get install -y python3.12

RUN apt-get install -y python3.12-venv

# Install other common C++ development tools
RUN apt-get install -y \
    cmake \
    gdb \
    valgrind

# Install GNU Standard C++ Library v3 (development files)
RUN apt-get install -y libstdc++-14-dev

# Install clangd-19
RUN apt-get install -y clangd-19

# Install vcpkg
RUN apt-get install -y unzip tar zip
RUN git clone https://github.com/Microsoft/vcpkg.git /opt/vcpkg
WORKDIR /opt/vcpkg
RUN ./bootstrap-vcpkg.sh && ./vcpkg integrate install && ./vcpkg integrate bash && echo 'export PATH=$PATH:/opt/vcpkg' >>~/.bashrc
WORKDIR /root Install vcpkg
ENV VCPKG_ROOT=/opt/vcpkg

# Install sqlite3
RUN apt-get install -y sqlite3

# Install bsdmainutils
RUN apt-get install bsdmainutils