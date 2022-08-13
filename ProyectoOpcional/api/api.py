from http import client
from flask import Flask, render_template, request
import socket
import threading

app = Flask(__name__)

# Members API Route

HEADER = 64
PORT = 80
SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER, PORT)
FORMAT = 'utf-8'
DISCONNECT_MESSAGE = "Disconect!"

# Este va a ser la ruta donde se va a presentar la pagina principal del api


@app.route('/admin/<tabla>')
def index():
    return render_template("index.html")


@app.route("/members")
def members():
    return {"members": ["Member1", "Member2", "Member3"]}


@app.route("/crear")
# Funcion que se encarga de crear un juego
def crearJuego():
    pass


# @app.route("admin/<juego>")
# def conseguirJuego(juego):
#    # Aqui se escribira el codigo para conseguir el juego deseado
#    pass


if __name__ == "__main__":
    app.run(debug=True)
    #ADDR = (SERVER, PORT)
    #client = socket.socket(socket.AF_INET)
    # client.connect(ADDR)
    # app.run(debug=True)
