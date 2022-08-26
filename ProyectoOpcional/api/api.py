from http import client
from logging import BASIC_FORMAT
import string
from sys import flags
from flask import Flask, render_template, request
import socket
import threading
from flask_cors import CORS
from elasticsearch import Elasticsearch
from formatos import BASETABLE

app = Flask(__name__)
CORS(app)

# ELASTIC_PASSWORD = "TKtXX7XfDRHtHcSZ78R1Z6tu"

# CLOUD_ID = "Elasticsearch:dXMtY2VudHJhbDEuZ2NwLmNsb3VkLmVzLmlvOjQ0MyQ3MmYzMTdhY2U1NTk0MTEyODNiNDRjMWIzNzdiNDA3NyRjNWMxNTMyZTdmYTE0OWZmOGQxYzJhMTI3NGQ1MWMxMg=="

# client = Elasticsearch(
#     cloud_id=CLOUD_ID,
#     basic_auth=("elastic", ELASTIC_PASSWORD)
# )

client = Elasticsearch(
    "https://localhost:9200",
    ca_certs="C:/Users/aryel/OneDrive/Desktop/TEC/http_ca.crt",
    basic_auth=("elastic", "5X4s2E9ImjCX35eZl97cS1i4"),
    verify_certs=False
)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# client.info()
# Members API Route

HEADER = 64
PORT = 80
SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER, PORT)
FORMAT = 'utf-8'
DISCONNECT_MESSAGE = "Disconect!"

# Este va a ser la ruta donde se va a presentar la pagina principal del api


@app.route("/prueba/<info>")
def prueba(info):
    print("Aqui se paso")
    pass


@app.route("/")
def index():
    pass


@app.route("/members")
def members():
    return {"members": ["Member1", "Member2", "Member3"]}


@app.route("/crear")
# Funcion que se encarga de crear un juego
# https://stackoverflow.com/questions/66049377/insert-new-document-using-python-elastic-client-raises-illegal-argument-exceptio
def crearJuego():
    bodyTable = BASETABLE
    s.sendall(b"Create Board")
    s.recv(1024)
    res = client.index(index="boards", body=bodyTable)
    # s.sendall(res.body["_id"])
    # s.recv(1024)
    return res._body


@app.route("/doesBoardExist/<id_board>")
def boardExist(id_board):
    query = client.exists(index="boards", id=id_board)
    if len(query._body["hits"]["hits"]) > 0:
        return query._body["hits"]["hits"][0]["_source"]["board"]["status"]
    return -1


@app.route("/searchBoardAnfitrion/<id_board>")
def searchBoard(id_board):
    query = client.exists(index="boards", id=id_board)
    if query.body == True:
        query = client.get(
            index="boards",
            id=id_board
        )
        #s.sendall("Load Board")
        # s.recv(1024)
        # s.sendall(id_board)
        # s.recv(1024)
        return query.body["_source"]
    return {
        "board": {
            "status": -1
        }
    }


@app.route("/searchBoardInvitado")
def searchBoardGuest():
    query = client.search(
        index="boards",
        query={
            "bool": {
                "must": [
                    {
                        "match": {
                            "board.status": 1
                        }
                    },
                    {
                        "match": {
                            "board.whiteTurn": 0
                        }
                    }
                ]
            }
        }
    )
    if len(query._body["hits"]["hits"]) > 0:
        return {
            "_id": query._body["hits"]["hits"][0]["_id"],
            "board": {
                "status": query._body["hits"]["hits"][0]["_source"]["board"]["status"]
            }
        }
    return {
        "board": {
            "status": -1
        }
    }


@app.route("/verificar/<sourceSquare>/<destinationSquare>")
def verifyMove(sourceSquare, destinationSquare):
    s.sendall(b"Move")
    s.recv(1024)
    s.sendall(bytes(sourceSquare, "utf-8"))
    s.recv(1024)
    s.sendall(bytes(destinationSquare, "utf-8"))
    res = s.recv(1024)
    return {"res": res.decode("utf-8")}


# @app.route("admin/<juego>")
# def conseguirJuego(juego):
#    # Aqui se escribira el codigo para conseguir el juego deseado
#    pass


if __name__ == "__main__":
    client.info()
    HOST = "localhost"  # The server's hostname or IP address
    PORT = 6666  # The port used by the server

    s.connect((HOST, PORT))

    app.run(host='0.0.0.0', port=80)
