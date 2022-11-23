import sys
from flask import Flask, jsonify
import socket
from flask_cors import CORS
import base64
from flask_swagger_ui import get_swaggerui_blueprint
import os
import json

PORT_API = 5000 #int(os.environ['PORT_API'])
IP_GOOGLE = "8.8.8.8" #os.environ['IP_GOOGLE']
PORT_GOOGLE = 53 #int(os.environ['PORT_GOOGLE'])

# Python flask
app = Flask(__name__)
CORS(app)

# UDP Socket
# https://pythontic.com/modules/socket/udp-client-server-example
server_address_port = (IP_GOOGLE, PORT_GOOGLE)
buffer_size = 1024

UDP_Client = socket.socket(
    socket.AF_INET, socket.SOCK_DGRAM)


@app.route("/api/dns_resolver/<dns_package>", methods=["POST", "GET"])
# Este es el metodo principal del proyecto
# Se va a recibir un paquete DNS RFC2929 codificado en base64
def dns_resolver(dns_package):
    decoded_package = base64.b64decode(dns_package)
    send = UDP_Client.sendto(decoded_package, server_address_port)
    reply = UDP_Client.recvfrom(1024)
    return jsonify({'response': str(base64.b64encode(reply[0]))})


# Docuentacion swagger
SWAGGER_ULR = "/swagger"
API_URL = '/static/Swagger.yaml'
swaggerui_blueprint = get_swaggerui_blueprint(
    SWAGGER_ULR,
    API_URL,
    config={
        "app_name": "DNS-API"
    }
)

app.register_blueprint(swaggerui_blueprint, url_prefix=SWAGGER_ULR)

if __name__ == "__main__":
    # localIP = "127.0.0.1"
    # localPort = 20001
    # bufferSize = 1024

    # msgFromServer = "Hello UDP Client"
    # bytesToSend = str.encode(msgFromServer)
    # UDPServerSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
    # UDPServerSocket.bind((localIP, localPort))
    # bytesAddressPair = UDPServerSocket.recvfrom(bufferSize)
    # mensaje = dns_resolver(bytesAddressPair[0])
    # UDPServerSocket.sendto(mensaje[0], bytesAddressPair[1])

    app.run(host='0.0.0.0', port=PORT_API, ssl_context='adhoc')

# Comandos de api
# pip install flask
# pip install flask_cors
# pip install pyopenssl
# pip install flash_swagger_ui
