FROM mcr.microsoft.com/quantum/iqsharp-base:0.12.20100504

USER root
COPY . ${HOME}
RUN chown -R ${USER} ${HOME}

USER ${USER}
