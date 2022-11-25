FROM python:3.10.6-slim-bullseye
WORKDIR /api
# We copy just the requirements.txt first to leverage Docker cache
COPY ./requirements.txt /api/requirements.txt
RUN pip3 install -r requirements.txt
COPY . /api
EXPOSE 5000
ENTRYPOINT [ "python" ]
CMD [ "DNS_API.py"]