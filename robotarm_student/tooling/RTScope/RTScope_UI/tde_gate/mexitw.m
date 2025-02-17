function mexitw

clear mex

mex tde_gate.c ../../RTScope_shared/incomm/libincomm_client.c -DWINDOWS -L../../RTScope_shared/incomm/ -lWS2_32
