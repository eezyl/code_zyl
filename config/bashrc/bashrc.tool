#!/bin/bash
# Author: zylin
# Email:  zylin@eda.ee.ntu.edu.tw

# gurobi
export GUROBI_HOME="/home/zylin/gurobi811/linux64"
export PATH="${PATH}:${GUROBI_HOME}/bin"
export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${GUROBI_HOME}/lib"