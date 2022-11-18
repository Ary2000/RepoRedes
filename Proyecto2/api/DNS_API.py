import sys
from flask import Flask
import socket
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
def dns_resolver(dns_package):
    decoded_package = base64.b64decode(dns_package)
    send = UDP_Client.sendto(decoded_package, server_address_port)
    reply = UDP_Client.recvfrom(1024)
    return reply


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
    if(len(sys.argv) != 2):
        print("Por favor mandar el ip del DNS")
    else:
        app.run(host='0.0.0.0', port=5000, ssl_context='adhoc')

# Comandos de api
# pip install flask
# pip install flask_cors
# pip install pyopenssl
# pip install flash_swagger_ui
