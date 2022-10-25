FROM gcc:latest

COPY . /tarea1

WORKDIR /tarea1

RUN gcc main.c -o tarea1

EXPOSE 9666/tcp

CMD ["./tarea1"]