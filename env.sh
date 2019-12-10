#!/bin/bash

PRGENV=`module -t list 2>&1 | grep PrgEnv`

module load cdt/19.08
module swap $PRGENV PrgEnv-gnu
module swap gcc gcc/8.3.0

module load cray-libsci/19.06.1


ARMPL_DIR=/opt/allinea/19.2.0.0/opt/arm/armpl-19.2.0_ThunderX2CN99_SUSE-12_gcc_8.2.0_aarch64-linux
export LLIBS="-L/opt/cray/pe/libsci/19.06.1/GNU/8.1/aarch64/lib -lsci_gnu_82_mp -lsci_gnu_82_mpi_mp"
export INCS="$INCS -I$ARMPL_DIR/include"
export LLIBS="$LLIBS -L$ARMPL_DIR/lib -larmpl -larmpl_lp64_mp"
export LD_LIBRARY_PATH="$ARMPL_DIR/lib:$LD_LIBRARY_PATH"
