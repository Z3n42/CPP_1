# pull official base image
FROM dpage/pgadmin4

# copy project
COPY ./entrypoint.sh /entrypoint_custom.sh

# Make entrypoint.sh executable
USER root
RUN chmod +x /entrypoint_custom.sh