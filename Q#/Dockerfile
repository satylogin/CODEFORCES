FROM mcr.microsoft.com/quantum/iqsharp-base:0.12.20082513

USER root
COPY . ${HOME}
RUN chown -R ${USER} ${HOME}

USER ${USER}
