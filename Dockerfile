FROM rootproject/root-ubuntu16

RUN sudo apt-get update && sudo apt-get install -y software-properties-common
RUN sudo add-apt-repository universe
RUN sudo apt-get install -y libboost-all-dev
