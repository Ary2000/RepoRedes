FROM gcc:latest

COPY . /game-controler

WORKDIR /game-controler

RUN gcc gameControler.c -o gc

CMD ["./gc"]