from http import client
from flask import Flask, render_template, request
import socket
import threading
from flask_cors import CORS
from elasticsearch import Elasticsearch

app = Flask(__name__)
CORS(app)

ELASTIC_PASSWORD = "TKtXX7XfDRHtHcSZ78R1Z6tu"

CLOUD_ID = "Elasticsearch:dXMtY2VudHJhbDEuZ2NwLmNsb3VkLmVzLmlvOjQ0MyQ3MmYzMTdhY2U1NTk0MTEyODNiNDRjMWIzNzdiNDA3NyRjNWMxNTMyZTdmYTE0OWZmOGQxYzJhMTI3NGQ1MWMxMg=="

client = Elasticsearch(
    cloud_id=CLOUD_ID,
    basic_auth=("elastic", ELASTIC_PASSWORD)
)

client.info()

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


@app.route("/doesBoardExist/<id_board>")
def boardExist(id_board):
    id_board = int(id_board)
    query = client.search(
        index="boards",
        query={
            "bool": {
                "must": [
                    {
                        "match": {
                            "board.id_board": id_board
                        }
                    },
                    {
                        "match": {
                            "board.status": 1
                        }
                    },
                    {
                        "match": {
                            "board.whiteTurn": 1
                        }
                    }
                ]
            }
        }
    )
    if len(query._body["hits"]["hits"]) > 0:
        return query._body["hits"]["hits"][0]["_source"]["board"]["status"]
    return -1


@app.route("/searchBoardAnfitrion/<id_board>")
def searchBoard(id_board):
    id_board = int(id_board)
    query = client.search(
        index="boards",
        query={
            "bool": {
                "must": [
                    {
                        "match": {
                            "board.id_board": id_board
                        }
                    },
                    {
                        "match": {
                            "board.status": 1
                        }
                    },
                    {
                        "match": {
                            "board.whiteTurn": 1
                        }
                    }
                ]
            }
        }
    )
    if len(query._body["hits"]["hits"]) > 0:
        return query._body["hits"]["hits"][0]["_source"]
    return {
        "board": {
            "status": -1
        }
    }


# @app.route("admin/<juego>")
# def conseguirJuego(juego):
#    # Aqui se escribira el codigo para conseguir el juego deseado
#    pass


if __name__ == "__main__":
    # client.info()
    app.run(host='0.0.0.0', port=PORT)
    #ADDR = (SERVER, PORT)
    #client = socket.socket(socket.AF_INET)
    # client.connect(ADDR)
    # app.run(debug=True)
