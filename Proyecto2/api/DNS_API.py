from http import client
from logging import BASIC_FORMAT
import string
import sys
import os
from flask import Flask, render_template, request
import socket
import threading
from flask_cors import CORS
from elasticsearch import Elasticsearch
import base64
from flask_swagger_ui import get_swaggerui_blueprint

# Python flask
app = Flask(__name__)
CORS(app)

# UDP Socket
# https://pythontic.com/modules/socket/udp-client-server-example
server_address_port = ("8.8.8.8", 53)
buffer_size = 1024

UDP_Client = socket.socket(
    socket.AF_INET, socket.SOCK_DGRAM)


@app.route("/api/dns_resolver/<dns_package>", methods=["POST"])
# Este es el metodo principal del proyecto
# Se va a recibir un paquete DNS RFC2929 codificado en base64
# Recordad lo del bit que hay que cambiar
def dns_resolver(dns_package):
    decoded_package = base64.b64decode(dns_package)
    header = '00000000000000010000000000000000000000000000000100000000000000000000000000000000000000000000000000000000'
    v = int(header, 2)
    b = bytearray()
    while v:
        b.append(v & 0xff)
        v >>= 8
    header = bytes(b[::-1])
    tail = '000000000000000000010000000000000001'
    # decoded_package = header + decoded_package
    request = b"".join([header, decoded_package])
    #send = UDP_Client.sendto(request, server_address_port)
    reply = UDP_Client.recvfrom(1024)
    reply_info = reply[0].decode()
    # return base64.b64encode(reply_info)
    return decoded_package


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
# app.register_blueprint(request_api.getblueprint())


if __name__ == "__main__":
    if(len(sys.argv) != 2):
        print("Por favor mandar el ip del DNS")
    else:
        server_address_port = (sys.argv[1], 53)
        app.run(host='0.0.0.0', port=5000)
