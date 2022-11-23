FROM gcc:latest

WORKDIR /dns_intercepter

COPY . /dns_intercepter/

RUN gcc server.c -o dns -lcurl

EXPOSE 53

CMD ["./dns"]