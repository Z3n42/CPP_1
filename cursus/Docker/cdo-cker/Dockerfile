### DOCKERFILE EN BLANCO!!! 

#FROM debian
FROM selenium/standalone-chrome

WORKDIR /tmp

COPY requirements.txt ./

RUN apt-get update && apt-get install -y \
	vim \
	python3 \
	python3-pip

RUN pip install --no-cache-dir --upgrade pip \
  && pip install --no-cache-dir -r requirements.txt

COPY . /tmp

# CMD ["python", "./req.py"]
