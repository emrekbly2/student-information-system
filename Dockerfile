FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    pkg-config \
    libpqxx-dev \
    libpq-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY CMakeLists.txt ./
COPY src ./src
COPY include ./include

RUN cmake -S . -B build -DBUILD_TESTS=OFF && cmake --build build -j

CMD ["./build/sis_app"]
