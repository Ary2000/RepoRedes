FROM mwaeckerlin/mingw:latest

COPY . /game-controler

WORKDIR /game-controler

RUN gcc gameControler.c -o gc.exe 

CMD ["./gc.exe"]