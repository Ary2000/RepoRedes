import sys
from flask import Flask, request, json, jsonify
import socket
from flask_cors import CORS
import base64
from flask_swagger_ui import get_swaggerui_blueprint
import os

PORT_API = int(os.environ['PORT_API'])
IP_GOOGLE = os.environ['IP_GOOGLE']
PORT_GOOGLE = int(os.environ['PORT_GOOGLE'])

# Python flask
app = Flask(__name__)
CORS(app)

# UDP Socket
# https://pythontic.com/modules/socket/udp-client-server-example
server_address_port = (IP_GOOGLE, PORT_GOOGLE)
buffer_size = 1024

UDP_Client = socket.socket(
    socket.AF_INET, socket.SOCK_DGRAM)


@app.route("/api/dns_resolver/", methods=["POST"])
# Este es el metodo principal del proyecto
# Se va a recibir un paquete DNS RFC2929 codificado en base64
def dns_resolver():
    data = json.loads(request.data)
    decoded_package = base64.b64decode(data["code"])
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

    app.run(host='0.0.0.0', port=PORT_API, ssl_context='adhoc')

# Comandos de api
# pip install flask
# pip install flask_cors
# pip install pyopenssl
# pip install flask_swagger_ui
