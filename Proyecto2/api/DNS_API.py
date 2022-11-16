from http import client
from logging import BASIC_FORMAT
import string
import sys
import os
from flask import Flask, render_template, request
import socket
import threading
from flask_cors import CORS
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
    #decoded_package = base64.b64decode(dns_package)
    # decoded_package = header + decoded_package
    #request = b"".join([header, decoded_package])
    send = UDP_Client.sendto(dns_package, server_address_port)
    reply = UDP_Client.recvfrom(1024)
    #reply_info = reply[0].decode()
    # return base64.b64encode(reply_info)
    #return decoded_package
    return reply[0]

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
        localIP     = "localhost"
        localPort   = 2000
        bufferSize  = 1024

        msgFromServer       = "Hello UDP Client"
        bytesToSend         = str.encode(msgFromServer)

        # Create a datagram socket
        UDPServerSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
        # Bind to address and ip
        UDPServerSocket.bind((localIP, localPort))
        print("UDP server up and listening")
        # Listen for incoming datagrams
        while(True):
            bytesAddressPair = UDPServerSocket.recvfrom(bufferSize)
            message = bytesAddressPair[0]
            address = bytesAddressPair[1]
            clientMsg = "Message from Client:{}".format(message)
            clientIP  = "Client IP Address:{}".format(address)
            print(clientMsg)
            print(clientIP)
            # Sending a reply to client
            respuesta = dns_resolver(bytesAddressPair[0])
            UDPServerSocket.sendto(respuesta, address)
            break
        #server_address_port = (sys.argv[1], 53)
        #app.run(host='0.0.0.0', port=5000)
