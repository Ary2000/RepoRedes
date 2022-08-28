FROM python:3.10.6-slim-bullseye
WORKDIR /app
# We copy just the requirements.txt first to leverage Docker cache
COPY ./requirements.txt /app/requirements.txt
COPY ./elastic_cred.txt /app/elastic_cred.txt 
COPY ./http_ca.crt /app/http_ca.crt 
RUN pip3 install -r requirements.txt
COPY . /app
EXPOSE 5000
ENTRYPOINT [ "python" ]
CMD [ "api.py", "elastic_cred.txt" ]