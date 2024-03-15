# Usa la imagen base de kasmweb/desktop:1.8.0-edge
FROM kasmweb/desktop:1.8.0-edge
USER root

# Actualiza la lista de paquetes e instala los paquetes necesarios
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    git \
    libglfw3 \
    libglfw3-dev && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Copia los archivos del directorio local al directorio '/app' en el contenedor
COPY . /home/kasm-user/fractol

# Define el comando por defecto que se ejecutará cuando el contenedor se inicie
CMD ["bash"]
