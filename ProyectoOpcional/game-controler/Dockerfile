FROM mwaeckerlin/mingw:latest

COPY . /game-controller

WORKDIR /game-controller

RUN gcc -o gc main.c 

CMD [“./gc”]